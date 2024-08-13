#ifndef MOVIESEARCHENGINE_BUFFERTOGGLE_H_
#define MOVIESEARCHENGINE_BUFFERTOGGLE_H_

//Idea stolen from -> https://cplusplus.com/forum/general/29137/

#include <termios.h>
#define STDIN_FILENO    0


class BufferToggle
{
    private:
        struct termios t;

    public:
         BufferToggle(){}

         ~BufferToggle(){
           on();
         }
        
        /*
         * Disables buffered input
         */

        void off(void)
        {
            tcgetattr(STDIN_FILENO, &t); //get the current terminal I/O structure
            t.c_lflag &= ~ICANON; //Manipulate the flag bits to do what you want it to do
            tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
        }

        /*
         * Enables buffered input
         */

        void on(void)
        {
            tcgetattr(STDIN_FILENO, &t); //get the current terminal I/O structure
            t.c_lflag |= ICANON; //Manipulate the flag bits to do what you want it to do
            tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
        }
};

#endif
