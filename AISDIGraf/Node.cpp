//
//  Node.cpp
//  AISDIGraf
//
//  Created by Hubert on 30.05.2015.
//  Copyright (c) 2015 Hubert. All rights reserved.
//

#include "Node.h"

Node::Node()
{
    x = 0;
    y = 0;
    vertexState = white;
}

Node::Node(double xCoordinate, double yCoordinate)
{
    x = xCoordinate;
    y = yCoordinate;
    vertexState = white;
}

