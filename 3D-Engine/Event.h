#pragma once


class Event
{
public:
	enum class Type
	{
		CloseEvent,
		ResizeEvent
	};

	Event(Type type)
	{
		Type = type;
	}

	Type Type;
};

