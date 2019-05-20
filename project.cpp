#include</home/sudharshan/Desktop/code/Stack/disp.cpp>
#include</home/sudharshan/Desktop/code/Stack/func.cpp>
void frontpage();
int main(int argc, char**argv)
{
    cout<<"Enter the maximum capacity of stack : ";
    cin>>scap;
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowPosition(10,10);
    glutInitWindowSize(700,700);
    glutCreateWindow("Simulation of Stack");
    glutDisplayFunc(frontpage);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
}
void frontpage()
{
    init();
    GLuint mmm = LoadTexture("cse.bmp");
    glBindTexture (GL_TEXTURE_2D, mmm);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-90, 90);
    glVertex2f(-90, -90);
    glVertex2f(90, -90);
    glVertex2f(90, 90);
    glEnd();
    glColor3f(1,1,1);
    printtext("VISVESVARAYA TECHNOLOGICAL UNIVERSITY",-60,80,37);
    printtext("BELGAVI, KARNATAKA - 590018",-40,70,27);
    printtext("A Minor Project on",-22,60,18);
    printtext("SIMULATION OF STACK",-40,48,19,3);
    printtext("Submitted in partial fulfullment for the Computer Graphics and Visualization",-58,33,76,2);
    printtext(" Laboratory course of Sixth Semester of Bachelor of Engineering in Computer",-60,29,75,2);
    printtext("Science & Engineering during the academic year 2018-19",-47,25,54,2);
    printtext("By",-1,10,2);
    printtext("Sudharshan V     4MN16CS040",-40,0,27);
    printtext("Punith Nayaka K  4MN16CS040",-40,-10,27);
    printtext("||Under the Guidance of||",-32,-20,25);
    printtext("Prof. Bharath Bharadwaj B S",-35,-30,27);
    printtext("Assistant Professor",-17,-34,19,2);
    printtext(" Dept. of CS&E",-14,-38,14,2);
    printtext("MIT Thandavpura",-16,-42,15,2);
    printtext("2018-19",-12,-50,7);
    printtext("DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING",-70,-60,44);
    printtext("MAHARAJA INSTITUTE OF TECHNOLOGY THANDAVAPURA",-73,-70,45);
    printtext("NH 766, Nanjangud Taluk, Mysuru - 571302",-50,-80,40);
    glBegin(GL_LINES);
    glVertex2f(-40,46);
    glVertex2f(39,46);
    glEnd();
    glutSwapBuffers();
}


void stack()
{
    init();
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-90, 90);
    glVertex2f(-90, -90);
    glVertex2f(90, -90);
    glVertex2f(90, 90);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-92, 92);
    glVertex2f(-92, -92);
    glVertex2f(92, -92);
    glVertex2f(92, 92);
    glEnd();
    q = s+100/scap;
    glColor3f(1,1,1);
    value = -50+(top+1)*(100/scap);
    if(top > -1)
    {
        for(int i=0,j=-50;i<=top;i++,j+=(100/scap))
        {
            glColor3f(0,0,1);
            draw_poly(-20, j+(100/scap), 20, j);
            glColor3f(1,1,1);
            printtext(st[i], 0-(l[i]+1)/2, j+(100/(scap*2)), l[i]);
        }
    }
    glColor3f(1,1,1);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-20,50);
    glVertex2f(-20,-50);
    glVertex2f(20,-50);
    glVertex2f(20,50);
    glEnd();
    
    for(int i=-50;i<=50;i+=(100/scap))
    {
        glBegin(GL_LINES);
        glVertex2f(-20,i);
        glVertex2f(20,i);
        glEnd();
    }
    glColor3f(1,1,1);
    print_top(scap);
    printtext("Stack Capacity : ", 40, 10, 17);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scap + 48);
    glColor3f(1.0,0.8372549019607843,0.8352941176470589);
    draw_poly(-80, 40, -50, 25);
    glColor3f(0,1,0);
    printtext("PUSH", -73, 30, 4);
    glColor3f(1.0,0.8372549019607843,0.8352941176470589);
    draw_poly(-80, 20, -50, 5);
    glColor3f(0,1,0);
    printtext("POP", -73, 10, 4);
    glColor3f(1.0,0.8372549019607843,0.8352941176470589);
    draw_poly(-80, 0, -50, -15);
    glColor3f(0,1,0);
    printtext("MPUSH", -73, -10, 5);
    glColor3f(1.0,0.8372549019607843,0.8352941176470589);
    draw_poly(-80, -20, -50, -35);
    glColor3f(0,1,0);
    printtext("MPOP", -73, -30, 5);
    singlepush();
    singlepop();
    multiplepush();
    multiplepop();
    glutSwapBuffers();
}
