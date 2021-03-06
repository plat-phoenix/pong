#ifndef WINDOW_H
#define WINDOW_H

#include "gfx.h"
#include "util/util.h"

#define key(k) (state.window.kbd[k])

struct Key {
    // Whether the key is held down
    bool down;
    // The value of `down` from the last frame
    bool last;
    // Whether the key has been pressed **once**
    bool tapped;
};

typedef int (*WinFn)(void);

struct Window {
    GLFWwindow *handle;
    // Keyboard
    struct Key kbd[GLFW_KEY_LAST];
    ivec2s size;
    WinFn init, destroy, update, render;

    u64 frames, fps;
    f64 last_second;
    bool wireframe;
};

int window_create(void);
void update_kbd(void);

#endif
