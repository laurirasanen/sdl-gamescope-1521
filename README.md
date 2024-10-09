Minimal sample for https://github.com/ValveSoftware/gamescope/issues/1521

```
meson setup build
ninja -C build
gamescope -s 0.1 --force-grab-cursor -- build/sdl-gamescope-1521
```

Hit space to toggle SDL_SetRelativeMouseMode.

In relative mode, SDL_MOUSEMOTION events wont be received unless moving mouse at a high enough speed.

