#ifndef VALUES_H
#define VALUES_H

class values
{
public:
    values();

    int getXStart();

    int getYStart();

    int getXEnd();

    int getYEnd();

    int getStrokeWidth();

    int getLineWidth();

    int getPaddingLeft();

    int getPaddingTop();

    int getNumFiels();

    int getFieldWidth();

    int getFieldHeight();

    int getPxVertical();

    int getPxHorizontal();

    int getFontSize();

    int getPortDistance();

    int getPortSpace();

    bool debugState();

private:
    bool debugging;
    int paddingTop;
    int paddingLeft;
    int strokeWidth;
    int lineWidth;
    int startX;
    int startY;
    int endX ;
    int endY ;
    int numFields;
    int fontSize;
    int portDistance;
    int portSpace;
};

#endif // VALUES_H
