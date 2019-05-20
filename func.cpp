void singlepush()
{
    if(push == true && fullstate == false)
    {
        empstate = false;
        glColor3f(1.0,0.8372549019607843,0.8352941176470589);
        draw_poly(-50, 70, 50, 60);
        glColor3f(0,1,0);
        printtext("Enter the element Insert : ", -48, 63, 27);
        int pos = 12;
        printtext(inp, pos, 63, linp);
        if(entered == true)
        {
            glColor3f(1.0,0.8372549019607843,0.8352941176470589);
            draw_poly(53, 70, 65, 60);
            glColor3f(0,1,0);
            printtext("GO", 55, 63, 2);
            if(go == true)
            {
                glColor3f(0,0,0);
                draw_poly(-50, 70, 65, 60);
                glColor3f(0,0,1);
                draw_poly(p, q, r, s);
                glColor3f(1,1,1);
                printtext(inp, 0-(linp+1)/2, s+(100/(scap*2)), linp);
                if(timepush == false)
                {
                    timepush = true;
                    timer1(0);
                }
                if(s <= value && top<scap)
                {
                    strcpy(st[++top],inp);
                    l[top] = linp;
                    strcpy(inp,"");
                    linp = 0;
                    push = false;
                    entered = false;
                    go = false;
                    timepush = false;
                    q = s+100/scap;
                    s = 100;
                }
            }
        }
    }
    else if(fullstate == true)
    {
        printtext("Stack Overflow Condition", -32, -60, 24);
    }
    glutPostRedisplay();
}
void singlepop()
{
    if(pop == true && empstate == false)
    {
        fullstate = false;
        if(b == 1000)
        {
            b = -50+(top+1)*(100/scap);
            d = b - 100/scap + 0.35;
        }
        glColor3f(0,0,0);
        draw_poly(-20, -50+(top+1)*(100/scap)-0.2, 19.65, -50+(top+1)*(100/scap) - 100/scap + 0.35);
        glColor3f(0,0,1);
        if(timepop == false)
        {
            timepop = true;
            timer2(0);
        }
        draw_poly(a, b, c, d);
        glColor3f(1,1,1);
        printtext(st[top], 0-(l[top]+1)/2, d+(100/(scap*2)), l[top]);
        if(d >= 100 && top>-1)
        {
            pop = false;
            timepop = false;
            top--;
            b = 1000;
        }
    }
    else if(empstate == true)
    {
        printtext("Stack Underflow Condition", -32, -60, 25);
    }
    glutPostRedisplay();
}
void multiplepush()
{
    if(mpush == true && fullstate == false)
    {
        empstate = false;
        glColor3f(1.0,0.8372549019607843,0.8352941176470589);
        draw_poly(-80, 70, 80, 60);
        glColor3f(0,1,0);
        printtext("Enter the multiple elements separated by space : ", -78, 63, 49);
        int pos = 37;
        char ch;
        glColor3f(0,1,0);
        printtext(inp, pos, 63, linp);
        if(mentered == true)
        {
            glColor3f(1.0,0.8372549019607843,0.8352941176470589);
            draw_poly(83, 70, 95, 60);
            glColor3f(0,1,0);
            printtext("GO", 85, 63, 2);
            if(go1 == true)
            {
                glColor3f(0,0,0);
                draw_poly(-80, 70, 95, 60);
                glColor3f(0,0,1);
                draw_poly(p, q, r, s);
                glColor3f(1,1,1);
                printtext(minp[pushed], 0-(leninp[pushed]+1)/2, s+(100/(scap*2)), leninp[pushed]);
                if(timepush == false)
                {
                    timepush = true;
                    timer1(0);
                }
                if(s <= value && top<scap)
                {
                    strcpy(st[++top],minp[pushed]);
                    l[top] = leninp[pushed];
                    strcpy(inp,"");
                    strcpy(minp[pushed],"");
                    linp = 0;
                    pushed++;
                    if(top == scap-1 && pushed <= iinp)
                    {
                        fullstate = true;
                        singlepush();
                        mpush = false;
                        mentered = false;
                        timepush = false;
                        q = s+100/scap;
                        s = 100;
                        iinp = 0;
                        jinp = 0;
                        pushed = 0;
                    }
                    else if(pushed > iinp)
                    {
                        mpush = false;
                        mentered = false;
                        go1 = false;
                        timepush = false;
                        q = s+100/scap;
                        s = 100;
                        iinp = 0;
                        jinp = 0;
                        pushed = 0;
                    }
                    else
                    {
                        q = s+100/scap;
                        s = 100;
                    } 
                }
            }
        }
    }
    glutPostRedisplay();
}

void multiplepop()
{
    if(mpop == true && empstate == false)
    {
        empstate = false;
        glColor3f(1.0,0.8372549019607843,0.8352941176470589);
        draw_poly(-50, 70, 50, 60);
        glColor3f(0,1,0);
        printtext("Enter the Number of elements to pop : ", -48, 63, 38);
        fullstate = false;
        int pos = 42;
        printtext(inp, pos, 63, linp);
        if(pentered == true)
        {
            glColor3f(1.0,0.8372549019607843,0.8352941176470589);
            draw_poly(53, 70, 65, 60);
            glColor3f(0,1,0);
            printtext("GO", 55, 63, 2);
            if(go == true)
            {
                if(b == 1000)
                {
                    b = -50+(top+1)*(100/scap);
                    d = b - 100/scap + 0.35;
                }
                glColor3f(0,0,0);
                draw_poly(-20, -50+(top+1)*(100/scap)-0.2, 19.65, -50+(top+1)*(100/scap) - 100/scap + 0.35);
                glColor3f(0,0,1);
                if(timepop == false)
                {
                    timepop = true;
                    timer2(0);
                }
                draw_poly(a, b, c, d);
                glColor3f(1,1,1);
                printtext(st[top], 0-(l[top]+1)/2, d+(100/(scap*2)), l[top]);
                if(d >= 100 && top>-1)
                {
                    poped++;
                    if(top == 0 && poped < len)
                    {
                        empstate = true;
                        singlepop();
                        top--;
                        mpop = false;
                        pentered = false;
                        timepop = false;
                        go = false;
                        strcpy(inp,"");
                        b = 1000;
                        poped = 0;
                    }
                    else if(poped < len)
                    {
                        b = 1000;
                        top--;
                    }
                    else if(poped >= len)
                    {
                        mpop = false;
                        pentered = false;
                        go = false;
                        timepop = false;
                        b = 1000;
                        top--;
                        strcpy(inp,"");
                        poped = 0;
                    }
                    
                }
            }
        }
    }
    glutPostRedisplay();
}