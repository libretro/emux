#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <input.h>
#include <util.h>

static bool sdl_init(video_window_t *window);
static void sdl_deinit();

bool sdl_init(video_window_t *UNUSED(window))
{
	return true;
}

void sdl_update()
{
	SDL_Event e;
	struct input_event event;

	/* Poll all events out of queue */
	while (SDL_PollEvent(&e)) {
		/* Fill input event structure according to detected event */
		switch (e.type) {
		case SDL_QUIT:
			event.type = EVENT_QUIT;
			input_report(&event, NULL);
			break;
		default:
			break;
		}
	}
}

void sdl_deinit()
{
}

INPUT_START(sdl)
	.init = sdl_init,
	.update = sdl_update,
	.deinit = sdl_deinit
INPUT_END

