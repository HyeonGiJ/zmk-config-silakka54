# Silakka54 rabbit display

Peripheral-only shield based on M165437/nice-view-gem v0.3.0
(`7794ebf7f75d7e16cb05240bcffe6c5a45ef5b44`). Use ZMK v0.3.

The West manifest fetches upstream GEM at `nice-view-gem`. This shield reuses
its status screen, battery/connection widgets, font, and peripheral screen.
Only the `draw_animation` implementation is replaced with a fixed 68x68
monochrome rabbit. The upper status area remains unchanged.

Kconfig defaults and display overlay are adapted from the pinned upstream
release under its MIT license (included here). The repository's root
`zephyr/module.yml` lets the ZMK reusable build workflow discover this shield.
The left half continues to use the original external `nice_view_gem` shield.

The canonical upright 69x68 artwork and enlarged visible preview are in `assets/`.
`tools/encode_rabbit.py` encodes it into LVGL 8 indexed 1-bit data, with byte-aligned rows and
an inversion-aware palette. The blank 69th column is removed and the sprite
is encoded clockwise by 90 degrees to match GEM's rotated status canvas.
`rabbit-native-68x68.png` shows native panel coordinates, not the user's view.
It requires Pillow and verifies decoding and inverse-rotation roundtrips.

Do not build/flash settings_reset or enable ZMK_SETTINGS_RESET_ON_START.
Studio settings and the USB RPC snippet are retained. Physical layout,
keymap, split roles, and storage partitions are not changed by this shield.
