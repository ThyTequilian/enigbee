#include "plugBoard.hpp"


auto PlugBoard::encode(const MessageElement& elem)->tl::expected<MessageElement, ENIGERR> {
	if (!checkElement(elem)) {
		return tl::make_unexpected(ENIGERR::elementOutOfRange);
	}
	MessageElement out = board[elem];
	return out;
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
	plug(L'a', L'e');
	plug(L'b', L'j');
	plug(L'c', L'm');
	plug(L'd', L'z');
	plug(L'f', L'l');
	plug(L'g', L'y');
	plug(L'h', L'x');
	plug(L'i', L'v');
	plug(L'k', L'w');
	plug(L'n', L'r');
	plug(L'o', L'q');
	plug(L'p', L'u');
	plug(L's', L't');
}