#include <stdio.h>
#include <SFML/Graphics.h>

int main() {
  sfVideoMode video = {1000, 1000, 32};
  sfEvent event;

  sfRenderWindow* window = sfRenderWindow_create(video, "SFML WORKS!", sfDefaultStyle, NULL);
  if (!window)
    return -1;

  sfCircleShape* circle = sfCircleShape_create();
  sfCircleShape_setRadius(circle, 25.f);

  sfColor color = {255, 0, 0, 255};

  sfCircleShape_setFillColor(circle, color);

  while (sfRenderWindow_isOpen(window)) {
    while (sfRenderWindow_pollEvent(window, &event)) {
      if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
      if (event.type == sfEvtResized) {
        sfFloatRect visibleArea = {0, 0, event.size.width, event.size.height};

        sfView* view = sfView_createFromRect(visibleArea);

        sfRenderWindow_setView(window, view);
      }
    }

    sfRenderWindow_clear(window, sfBlack);

    sfRenderWindow_drawCircleShape(window, circle, NULL);

    sfRenderWindow_display(window);
  }

  sfCircleShape_destroy(circle);

  return 0;
}