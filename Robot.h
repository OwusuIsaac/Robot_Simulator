#include <iostream>
#include <cmath>
#include <SDL.h>
#include <Stdio.h>
#include "Segment.h"

class Robot {
private:
    int numOfsegments;
    Segment* address;
public:
    Robot() {
        Segment root_segment(0, 0);
        address = &root_segment;
        numOfsegments = 1;
    }
    Robot(int num) {
        double Angle, length;
        numOfsegments = num;
        Segment root_segment(0, 0);
        address = new Segment[numOfsegments];
        address[0] = root_segment;
        address[0].printSegmentInfo();
        cout << " " << endl;
        for (int i = 1; i < numOfsegments; i++)
        {
            address[i].set_start(address[i - 1].get_endPoint_x(), address[i - 1].get_endPoint_y());
            cout << "Enter length for segment number " << i + 1 << endl;
            cin >> length;
            address[i].set_length(length);
            cout << "Enter angle for segment number " << i + 1 << endl;
            cin >> Angle;
            address[i].set_angle(Angle);
            address[i].printSegmentInfo();
            cout << " " << endl;
        }
    }
    // member function take outs a segment 
    void takeOut() {
        int takeOut;
        cout << "Enter number of segments to take out" << endl;
        cin >> takeOut;
        if (numOfsegments > takeOut) {
            Segment* temp = new Segment[numOfsegments - takeOut];
            for (int i = 0; i < (numOfsegments - takeOut); i++)
                temp[i] = address[i];
            delete[]address;
            address = temp;
            numOfsegments -= takeOut;
            for (int i = 0;i < numOfsegments;i++)
                address[i].printSegmentInfo();
            cout << " " << endl;
        }
        else
            cout << "Sorry, no additional take outs can be done" << endl;
    }
    // member function adds a segment 
    void Add() {
        int add;
        cout << "Enter number of segments to add" << endl;
        cin >> add;
        double Angle, length;
        Segment* temp = new Segment[numOfsegments + add];
        for (int i = 0; i < numOfsegments; i++) {
            temp[i] = address[i];
        }
        for (int j = numOfsegments; j < (numOfsegments + add); j++) {
            temp[j].set_start(temp[j - 1].get_endPoint_x(), temp[j - 1].get_endPoint_y());
            cout << "Enter length for segment number " << j + 1 << endl;
            cin >> length;
            temp[j].set_length(length);
            cout << "Enter angle for segment number" << j + 1 << endl;
            cin >> Angle;
            temp[j].set_angle(Angle);
            temp[j].printSegmentInfo();
            cout << " " << endl;
        }
        delete[]address;
        address = temp;
        numOfsegments += add;
    }
    // member function sets all the segments to the horizontal axis
    void set_Default_Position() {
        address[0].set_angle(0);
        address[0].printSegmentInfo();
        cout << " " << endl;
        for (int i = 1; i < numOfsegments; i++) {
            address[i].set_angle(0);
            address[i].set_start(address[i - 1].get_endPoint_x(), address[i - 1].get_endPoint_y());
            address[i].printSegmentInfo();
            cout << " " << endl;
        }

    }
    // member function finds the coordinate of the end point of the last segment
    void forwardKinematics() {
        double* ptr = new double[numOfsegments];
        for (int i = 0; i < numOfsegments; i++) {
            cout << "Enter angle for segment " << i + 1 << endl;
            cin >> ptr[i];
        }
        address[0].set_angle(ptr[0]);
        address[0].printSegmentInfo();
        for (int i = 1; i < numOfsegments; i++) {
            address[i].set_angle(ptr[i]);
            address[i].set_start(address[i - 1].get_endPoint_x(), address[i - 1].get_endPoint_y());
        }
        cout << "Point_end effector (" << address[numOfsegments - 1].get_endPoint_x() << "," << address[numOfsegments - 1].get_endPoint_y() << ")." << endl;
        delete[] ptr;
    }
    // Function read into a file
    void plotStart() {
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
            SDL_Window* window = NULL;
            SDL_Renderer* renderer = NULL;

            if (SDL_CreateWindowAndRenderer(900, 700, 0, &window, &renderer) == 0) {
                SDL_bool done = SDL_FALSE;

                while (!done) {
                    SDL_Event event;


                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                    SDL_RenderClear(renderer);
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawLine(renderer, 0, 350, 900, 350);
                    SDL_RenderDrawLine(renderer, 450, 0, 450, 700);
                    for (int i = 0; i < numOfsegments; i++) {
                        SDL_RenderDrawLine(renderer, address[i].get_startPoint_x() + 450, 350 - address[i].get_startPoint_y(), address[i].get_endPoint_x() + 450, 350 - address[i].get_endPoint_y());
                        SDL_RenderPresent(renderer);
                    }
                    while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) {
                            done = SDL_TRUE;
                        }
                    }
                }
                if (renderer) {
                    SDL_DestroyRenderer(renderer);
                }
                if (window) {
                    SDL_DestroyWindow(window);
                }
            }
        }
        SDL_Quit();
    }

};
