# igfxtweak
Intel Graphics tweak tool

igfxtweak provides access to dithering settings of Intel GPUs, which support 4 dithering configurations:
- Spatial
- Spatio-Temporal
- Spatio-Temporal 2
- Temporal

Since Intel intentionally disables dithering and FRC for external displays with <8bpc
and Intel Graphics Control Panel doesn't provide a corresponding option, this tool may
be used as a workaround.

igfxtweak requires administrator privileges to execute properly.

## Usage

Each video output (pipe) has its own dithering configuration and you can configure them independently:
- `igfxtweak dithering sp-a` - enables spatial dithering on Pipe A
- `igfxtweak dithering st1-a` - enables spatio-temporal dithering on Pipe A
- `igfxtweak dithering st2-a` - enables spatio-temporal dithering (variant 2) on Pipe A
- `igfxtweak dithering no-a` - disables dithering on Pipe A
- `igfxtweak dithering sp-a sp-b sp-c sp-d` - enables spatial dithering on Pipe A, Pipe B, Pipe C and Pipe D
