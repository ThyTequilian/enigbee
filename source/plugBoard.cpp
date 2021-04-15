#include "plugBoard.hpp"


auto PlugBoard::encode(const MessageElement& text)->tl::expected<MessageElement, ENIGERR> {


	return text;

}

auto PlugBoard::plug(const MessageElement& from, const MessageElement& to)->tl::expected<void, ENIGERR> {
	if (!checkElement(from) || !checkElement(to)) {
		return tl::make_unexpected(ENIGERR::elementOutOfRange);
	}

}
void constexpr PlugBoard::createBoard() {
	for (auto i = L'a'; i <= L'z'; i++) {
		board[i] = i;
	}
}


//returns true if element is in range. Else false
bool PlugBoard::checkElement(const MessageElement& element) {
	return (L'a' <= element && L'z' >= element);
}