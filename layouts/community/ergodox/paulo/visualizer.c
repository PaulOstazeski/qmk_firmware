/*
Note: this is a modified copy of ../default/visualizer.c, originally licensed GPL.
*/

#include "simple_visualizer.h"
#include "util.h"

// Copied from keymap.c
enum custom_layers {
    _QWERTY,
    _NUM,
    _MOUSE,
};

#define RED 0
#define ORANGE 21
#define YELLOW 42
#define SPRING_GREEN 64
#define GREEN 85
#define TURQUOISE 107
#define CYAN 127
#define OCEAN 149
#define BLUE 170
#define VIOLET 192
#define MAGENTA 212
#define RASPBERRY 234

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    uint8_t layer = biton32(state->status.layer);

    switch(layer) {
      case(_QWERTY):
        state->target_lcd_color = LCD_COLOR(RASPBERRY, 255, 0xFF);
        state->layer_text = "Alpha";
        break;
      case(_NUM):
        state->target_lcd_color = LCD_COLOR(CYAN, 255, 0xFF);
        state->layer_text = "Symbol";
        break;
      case(_MOUSE):
        state->target_lcd_color = LCD_COLOR(YELLOW, 255, 0xFF);
        state->layer_text = "Mouse";
        break;
    }
}
