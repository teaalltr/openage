// Copyright 2015-2023 the openage authors. See copying.md for legal info.

#pragma once

#include <memory>

namespace qtsdl {

class GuiRenderer;
class GuiEventQueue;
class GuiInputImpl;

/**
 * Converts SDL input events into Qt events.
 */
class GuiInput {
public:
	explicit GuiInput(GuiRenderer *renderer, GuiEventQueue *game_logic_updater);
	~GuiInput();

	/**
	 * Returns true if the event was accepted.
	 */
	bool process(/* SDL_Event *event */);

private:
	friend class GuiInputImpl;
	std::unique_ptr<GuiInputImpl> impl;
};

} // namespace qtsdl
