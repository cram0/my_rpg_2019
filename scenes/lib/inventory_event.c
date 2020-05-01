#include "inventory.h"

int key_is_arrow(sfEvent event)
{
    if (event.key.code != sfKeyLeft &&
        event.key.code != sfKeyRight &&
        event.key.code != sfKeyUp &&
        event.key.code != sfKeyDown)
        return (0);
    return (1);
}

void move_cursor(items *item, sfEvent event)
{
    int mvx = 0, mvy = 0;
    if (!key_is_arrow(event)) return;
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyUp) mvy -= 5;
        if (event.key.code == sfKeyRight && (item->cursor_pos + 1) % 5 != 0)
            mvx += 1;
        if (event.key.code == sfKeyDown) mvy += 5;
        if (event.key.code == sfKeyLeft && item->cursor_pos % 5 != 0)
            mvx -= 1;
    }
    if (item->cursor_pos + mvx + mvy < 0 ||
        item->cursor_pos + mvx + mvy > 19) return;
    if (item->cursor_item != 0) {
        if (slot[item->cursor_pos + mvx + mvy].occuped != 0) return;
        slot[item->cursor_old].occuped = 0;
        slot[item->cursor_pos].occuped = item->cursor_item;
        draw_item(item);
    }
    item->cursor_old = item->cursor_pos;
    item->cursor_pos += mvx + mvy;
}

void cursor_selection(items *item, sfEvent event)
{
    if (event.key.code != sfKeySpace)
        return;
    if (event.type == sfEvtKeyReleased) {
        if (event.key.code == sfKeySpace && item->cursor_item == 0) {
            item->cursor_item = slot[item->cursor_pos].occuped;
        } else {
            item->cursor_item = 0;
        }
    }
}

void equipe_item(items *item, sfEvent event)
{
    if (event.key.code != sfKeyE)
        return;
    if (event.type == sfEvtKeyReleased) {
        if (item->equiped != slot[item->cursor_pos].occuped)
            item->equiped = slot[item->cursor_pos].occuped;
        else
            item->equiped = 0;
    }
}

void inventory_interaction(items *item, sfEvent event)
{
    if (item->lock == 1) {
        mouse_cursor(item, event);
        move_cursor(item, event);
        cursor_selection(item, event);
        equipe_item(item, event);
    }
    if (event.key.code != sfKeyI)
        return;
    if (event.type == sfEvtKeyReleased) {
        if (item->lock == 0 || item->lock == 2) {
            item->lock = 1;
        } else {
            item->lock = 2;
        }
    }
}