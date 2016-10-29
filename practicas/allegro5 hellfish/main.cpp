#include <iostream>
#include <allegro5/allegro5.h>

using namespace std;

ALLEGRO_DISPLAY *display;

int main(void) {

    al_init();

    display=al_create_display(800,600);

    al_clear_to_color(al_map_rgb(255,0,0));

    al_flip_display();

    al_rest(5);

    al_destroy_display(display);

    return 0;
}
