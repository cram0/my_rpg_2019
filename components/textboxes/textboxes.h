#ifndef COMPONENTS_TEXTBOXES_H
#define COMPONENTS_TEXTBOXES_H

#include <SFML/Graphics.h>

typedef struct {
    float win_width;
    float win_height;

    sfFont *font;

    int on;
    float offset;
    int charcount;
    sfRenderTexture *texture;
    char string[1024];

    sfClock *clock;
} textbox_state;

int init_textbox(textbox_state *state, float width, float height);
int draw_textbox(textbox_state *state, sfRenderWindow *window);
int update_textbox(textbox_state *state);
void reset_textbox(textbox_state *state);
void destroy_textbox(textbox_state *state);

#endif