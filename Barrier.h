#pragma once
class Barrier
{
private:
	char value;

public:
	void setValue(char value) {
		this->value = value;
	}
	char getValue() {
		return value;
	}

	Barrier() {
		value = '#';
	}
	
};

