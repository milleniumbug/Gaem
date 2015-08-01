// The MIT License (MIT)

// Copyright (c) 2015 Skorezore

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.


#pragma once


#include <deque>
#include "coords.hpp"
#include "curses.hpp"
#include "gaem_screen.hpp"


class entity {
public:
	coords position{0, 0};
	std::deque<coords> prev_positions;
	int health = 100;
	char body;
	attr_t colour;


	entity(char thebody, attr_t attrs = A_NORMAL);
	entity(const entity &) = default;
	entity(entity &&) = default;

	virtual ~entity() = default;

	entity & operator=(const entity &) = default;
	entity & operator=(entity &&) = default;

	void move_to(const coords & where);

	virtual bool is_player() const;
	virtual coords movement_destination(const gaem_screen & screen, int key) = 0;
};
