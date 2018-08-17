#include "input.h"

namespace Lord1 { namespace input {

	Input::Input()
	{
		for (int i = 0; i < KEY_AMOUNT; ++i)
		{
			_keysPressed[i] = false;
			_keysTyped[i] = false;
			_keysReleased[i] = false;
		}
	}

	void Input::update()
	{

		static bool keyEventHappened = false;

		if (keyEventHappened)
		{
			for (int i = 0; i < KEY_AMOUNT; ++i)
			{
				_keysReleased[i] = false;
				_keysTyped[i] = false;
			}
			keyEventHappened = false;
		}


		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			bool keydown = (ev.type == SDL_KEYDOWN);
			bool keyup = (ev.type == SDL_KEYUP);
			if (keydown || keyup)
			{
				Key key = translateSDLKey(ev.key.keysym.sym);

				if (key == KEY_NULL) continue;

				keyEventHappened = true;

				if (keydown)
				{
					_keysPressed[key] = true;
					_keysTyped[key] = true;
				}
				else if (keyup)
				{
					_keysReleased[key] = true;
					_keysPressed[key] = false;

				}
			}
		}
	}

	bool Input::poll(Key key, KeyState state) const
	{
		if (state >= KEY_AMOUNT)
			return false;

		switch (state)
		{
		case KEYSTATE_PRESSED:
			return _keysPressed[key];
		case KEYSTATE_TYPED:
			return _keysTyped[key];
		case KEYSTATE_RELEASED:
			return _keysReleased[key];
		default:
			return false;
		}
	}

	bool Input::poll(Key key) const
	{
		return poll(key, KEYSTATE_PRESSED);
	}

	Key Input::translateSDLKey(SDL_Keycode key)
	{
		switch (key)
		{
		case SDLK_a:
			return KEY_A;
		case SDLK_b:
				return KEY_B;
		case SDLK_c:
				return KEY_C;
		case SDLK_d:
				return KEY_D;
		case SDLK_e:
				return KEY_E;
		case SDLK_f:
				return KEY_F;
		case SDLK_g:
				return KEY_G;
		case SDLK_h:
				return KEY_H;
		case SDLK_i:
				return KEY_I;
		case SDLK_j:
				return KEY_J;
		case SDLK_k:
				return KEY_K;
		case SDLK_l:
				return KEY_L;
		case SDLK_m:
				return KEY_M;
		case SDLK_n:
				return KEY_N;
		case SDLK_o:
				return KEY_O;
		case SDLK_p:
				return KEY_P;
		case SDLK_q:
				return KEY_Q;
		case SDLK_r:
				return KEY_R;
		case SDLK_s:
				return KEY_S;
		case SDLK_t:
				return KEY_T;
		case SDLK_u:
				return KEY_U;
		case SDLK_v:
				return KEY_V;
		case SDLK_w:
				return KEY_W;
		case SDLK_x:
				return KEY_X;
		case SDLK_y:
				return KEY_Y;
		case SDLK_z:
				return KEY_Z;
		case SDLK_SPACE:
				return KEY_SPACE;
		case SDLK_RETURN:
				return KEY_ENTER;
		case SDLK_ESCAPE:
				return KEY_ESCAPE;
		case SDLK_LCTRL:
				return KEY_LCTRL;
		case SDLK_RCTRL:
				return KEY_RCTRL;
		case SDLK_LALT:
				return KEY_LALT;
		case SDLK_RALT:
				return KEY_RALT;
		default:
			return KEY_NULL;
		}
	}
}}

