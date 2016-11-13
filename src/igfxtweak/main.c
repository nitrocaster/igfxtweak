#include "config.h"
#include "platform.h"
#include "igfx_device.h"
#include "igfx_db.h"
#include "WinRing0.h"
#include "InpOut.h"
#include <stdio.h>

static void print_usage()
{
    const char *usage_str = "usage: igfxtweak <option> [<values>]";
    puts(usage_str);
}

int main(int argc, char *argv[])
{
    int result = 0;
    if (argc>=2)
    {
        // initialize api
        if (!WinRing0Initialize())
        {
            puts("WinRing0: initialization failed.");
            goto error;
        }
        if (!InpOutInitialize())
        {
            puts("InpOut: initialization failed.");
            goto error;
        }
        // detect device
        uint32_t addr;
        uint16_t ven_id, dev_id;
        if (igfx_device_find(&addr, &ven_id, &dev_id))
        {
            puts("device lookup failed.");
            goto error;
        }
        // find detected device in igfx_db
        device_entry_t *dev = device_db;
        uint32_t type = 0;
        while (dev->type)
        {
            if (dev->ven_id==ven_id && dev->dev_id==dev_id)
            {
                type = dev->type;
                break;
            }
            dev++;
        }
        if (!type)
        {
            puts("device not supported.");
            goto error;
        }
        type--;
        // find option
        const char *option = argv[1];
        uint32_t bar0 = option_db[type].bar0;
        uint32_t bar1 = option_db[type].bar1;
        const option_entry_t *opt = option_db[type].options;
        while (opt->desc_s)
        {
            if (!strcmp(opt->desc_s, option))
                break;
            opt++;
        }
        if (!opt->desc_s)
        {
            puts("no such option.");
            goto error;
        }
        if (argc>2)
        {
            // write option values
            uint32_t iobase_l, iobase_h;
            if (igfx_device_get_iobase(addr, bar0, bar1, &iobase_l, &iobase_h))
            {
                puts("failed to get device iobase.");
                goto error;
            }
            char **values = argv+2;
            uint32_t nvalues = argc-2;
            for (uint32_t i = 0; i<nvalues; i++)
            {
                char *value = values[i];
                const option_value_t *opt_val = opt->values;
                while (opt_val->desc_s)
                {
                    if (!strcmp(opt_val->desc_s, value))
                        break;
                    opt_val++;
                }
                if (!opt_val->desc_s)
                {
                    printf("no such value: '%s'\n", value);
                    goto error;
                }
                uint32_t rdata = 0;
                uint32_t mask = opt_val->reg_mask;
                uint32_t data = opt_val->reg_data;
#ifdef PLATFORM_X64
                uint8_t *phys_addr = (uint8_t *)(opt_val->reg_address+((iobase_l | iobase_h<<32)&0xFFFFFFFFFFFFFF00));
#else
                uint8_t *phys_addr = (uint8_t *)(opt_val->reg_address+(iobase_l&0xFFFFFF00));
#endif                
                if (igfx_device_read(phys_addr, opt_val->reg_size, (uint8_t *)&rdata))
                {
                    puts("failed to read register.");
                    goto error;
                }
                uint32_t new_data = data & mask | rdata & ~mask;
                if (new_data==rdata)
                    continue;
                if (igfx_device_write(phys_addr, opt_val->reg_size, (uint8_t *)&new_data))
                {
                    puts("failed to write register.");
                    goto error;
                }
            }
        }
        else
        {
            puts("value expected.");
            goto error;
        }
        goto cleanup;
    }
    print_usage();
error:
    result = 1;
cleanup:
    igfx_device_unmap();
    InpOutDeinitialize();
    WinRing0Deinitialize();
    return result;
}
