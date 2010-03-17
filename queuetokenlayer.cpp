#include "queuetokenlayer.h"
#include "token.h"
#include <cassert>

QueueTokenLayer::QueueTokenLayer(TokenSource* input)
	: TokenLayer(input), queue_()
{
}

QueueTokenLayer::~QueueTokenLayer()
{
	clear_queue();
}

void QueueTokenLayer::enqueueOutputToken(Token *t)
{
	assert(t);
	queue_.push(t);
}

Token* QueueTokenLayer::getNextToken()
{
	if (queue_.empty()) {
		prepareMoreTokens();
	}
	if (queue_.empty()) {
		return NULL;
	} else {
		Token* t = queue_.front();
		queue_.pop();
		return t;
	}
}

void QueueTokenLayer::clear_queue()
{
	while (!queue_.empty()) {
		Token* t = queue_.front();
		delete t;
		queue_.pop();
	}
}

void QueueTokenLayer::reset()
{
	clear_queue();
}
