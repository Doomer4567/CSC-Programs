#ifndef Text_H
#define Text_H

class Text {
    public:
    //Functions
        Text(const char*);
       ~Text();
        void displayText() const;
        const char* getText() const;
        int getLength() const;
    private:
    //Array
        const char* textArray;
        int textLength;
};

#endif 