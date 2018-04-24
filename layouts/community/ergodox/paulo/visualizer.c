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

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    uint8_t layer = biton32(state->status.layer);

    switch(layer) {
      case(_QWERTY):
        state->target_lcd_color = LCD_COLOR(240, 100, 0xFF);
        state->layer_text = "Alpha";
        break;
      case(_NUM):
        state->target_lcd_color = LCD_COLOR(0, 100, 0xFF);
        state->layer_text = "Symbol";
        break;
      case(_MOUSE):
        state->target_lcd_color = LCD_COLOR(60, 100, 0xFF);
        state->layer_text = "Mouse";
        break;
    }
}
