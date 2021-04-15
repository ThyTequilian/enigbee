#include "plugBoard.hpp"


auto PlugBoard::encode(const MessageElement& element)->tl::expected<MessageElement, ENIGERR> {
	if (!checkElement(element)) {
		return tl::make_unexpected(ENIGERR::elementOutOfRange);
	}

	return board[element];
}

auto PlugBoard::plug(const MessageElement& from, const MessageElement& to)->tl::expected<void, ENIGERR> {
	auto lFrom = std::tolower(from);
	auto lTo = std::tolower(to);
	if (!checkElement(lFrom) || !checkElement(lTo)) {
		return tl::make_unexpected(ENIGERR::elementOutOfRange);
	}

	board[lFrom] = lTo;
	board[lTo] = lFrom;
}

void PlugBoard::createBoard() {
	for (auto i = L'a'; i <= L'z'; i++) {
		board[i] = i;
	}
}

//returns true if element is in range. Else false
bool PlugBoard::checkElement(const MessageElement& element) {
	return (L'a' <= element && L'z' >= element);
}

void PlugBoard::presetBoard0() {
	plug(L'a', L't');
	plug(L'b', L's');
	plug(L'c', L'u');
	plug(L'd', L'z');
	plug(L'e', L'w');
	plug(L'f', L'y');
	plug(L'g', L'r');
	plug(L'h', L'p');
	plug(L'i', L'k');
	plug(L'j', L'n');
}

void PlugBoard::returnBoard() {
	plug(L'a', L'u');
	plug(L'b', L'w');
	plug(L'c', L'k');
	plug(L'd', L'z');
	plug(L'e', L't');
	plug(L'f', L'r');
	plug(L'g', L'p');
	plug(L'h', L'n');
	plug(L'i', L'y');
	plug(L'j', L's');
}