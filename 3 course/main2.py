# Импортируем все необходимые библиотеки:
import numpy as numpy
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from PIL import Image as Image
import sys
import math

# Объявляем все глобальные переменные
from PIL import Image

global xrot         # Величина вращения по оси x
global yrot         # Величина вращения по оси y
global ambient      # рассеянное освещение
global greencolor   # Цвет зеленый
global redcolor    # Цвет елочного стебля
global bluecolor
global lightpos     # Положение источника освещения
global drowmode  # для перемещение куба и цилиндра
global drowmode2 # для перемещения сферы и конуса
global laba1  # выблор какой лабы показывать чайник
global laba2  #
global xlig
global ylig
global zlig

global step

global x1
global y1
global z1

global rotat

global qobj

# Процедура инициализации
def init():
    global xrot         # Величина вращения по оси x
    global yrot         # Величина вращения по оси y
    global ambient      # Рассеянное освещение
    global greencolor   # Цвет зеленый
    global redcolor    # Цвет красный
    global lightpos     # Положение источника освещения
    global xlig
    global ylig
    global zlig
    global drowmode
    global drowmode2
    global laba1
    global laba2
    global bluecolor
    global yy
    global xx
    global step
    global x1
    global y1
    global z1
    global rotat

    global qobj

    step = 0
    xx = 3
    yy = 0
    x1 = 0
    y1 = 0
    z1 = 0
    rotat = 0


    laba1 = True # первоначальная инициализация отрисовывающейся лабы
    laba2 = False
    drowmode = False
    drowmode2 = False

    xlig = 1.0
    ylig = 1.0
    zlig = 1.0

    xrot = 0.0                          # Величина вращения по оси x = 0
    yrot = 0.0                          # Величина вращения по оси y = 0
    ambient = (0.9, 0.9, 0.9, 1)        # Первые три числа цвет в формате RGB, а последнее - яркость
    bluecolor = (0, 0.3, 0.6, 0)  # Зеленый цвет
    greencolor = (0.2, 0.8, 0.0, 0.8)   # Зеленый цвет
    redcolor = (0.9, 0.1, 0.1, 1)    # красный цвет
    lightpos = (1.0, 1.0, 1.0)          # Положение источника освещения по осям xyz

    glClearColor(0.7, 0.7, 0.7, 1.0)                # Серый цвет для первоначальной закраски
    gluOrtho2D(-6.0, 6.0, -6.0, 6.0)                # Определяем границы рисования по горизонтали и вертикали
    # glRotatef(-90, 0.0, 0.0, 0.0)                   # Сместимся по оси Х на 90 градусов
    # glRotatef(-90, -0.0, 0.0, 0.0)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient) # Определяем текущую модель освещения
    glEnable(GL_LIGHTING)                           # Включаем освещение
    glEnable(GL_LIGHT0)                             # Включаем один источник света
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos)     # Определяем положение источника света

    tex = read_texture('pp.jpg')  # текстурная сфера
    qobj = gluNewQuadric()
    gluQuadricTexture(qobj, GL_TRUE)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, tex)
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE)




# Процедура обработки специальных клавиш
def specialkeys(key, x, y):
    global ambient
    global xrot
    global yrot
    global laba1
    global laba2
    global drowmode
    global drowmode2
    global lightpos
    global xlig
    global ylig
    global zlig

    global yy
    global xx
    global step
    global x1
    global y1
    global z1
    global rotat

    # Обработчики для клавиш со стрелками

    if key == GLUT_KEY_UP:      # Клавиша вверх
        xrot -= 2.0             # Уменьшаем угол вращения по оси Х
    if key == GLUT_KEY_DOWN:    # Клавиша вниз
        xrot += 2.0             # Увеличиваем угол вращения по оси Х
    if key == GLUT_KEY_LEFT:    # Клавиша влево
        yrot -= 2.0             # Уменьшаем угол вращения по оси Y
    if key == GLUT_KEY_RIGHT:   # Клавиша вправо
        yrot += 2.0             # Увеличиваем угол вращения по оси Y
    if key == GLUT_KEY_HOME: # если нажата кнопка home будет отриосываться чаник и цилиндр
        drowmode = True
        laba1 = True
        laba2 = False
    if key == GLUT_KEY_INSERT: # если нажата кнопка insert чайник отрисуется на цилиндре
        drowmode = False
        laba1=True
        laba2=False
    if key == GLUT_KEY_PAGE_UP: # если нажата кнопка page up будет отрисован тор и конус
        drowmode2 = True
        laba1 = False
        laba2 = True
    if key == GLUT_KEY_PAGE_DOWN: # если нажата кнопка page up будет отрисован тор и конус
        drowmode2 = False
        laba1 = False
        laba2 = True

    if key == 1:      # Клавиша вверх
        xlig += 1.0
    if key == 2:      # Клавиша вверх
        xlig -= 1.0
    if key == 3:      # Клавиша вверх
        ylig += 1.0
    if key == 4:      # Клавиша вверх
        ylig -= 1.0
    if key == 5:      # Клавиша вверх
        zlig += 1.0
    if key == 6:  # Клавиша вверх
        zlig -= 1.0
    if key == 7:  # Клавиша вверх
        ambient = (0.0, 0.0, 0.0, 1)
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient)
    if key == 8:  # Клавиша вверх
        ambient = (1.0, 1.0, 1.0, 1)
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient)
    if key == 9:  # Клавиша вверх
        ambient = (1.0, 1.0, 1.0, 0)
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient)
    if key == 10:  # Клавиша вверх
        ambient = (1.0, 0.0, 0.0, 1)
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient)
    if key == 11:  # Клавиша вверх
        ambient = (0.0, 1.0, 0.0, 1)
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient)
    if key == 12:  # Клавиша вверх

        # xx = 3*math.cos(45)
        # yy = 3*math.sin(45)
        # xx += math.pi/180
        step += 1
        rotat += 1
        if step == 361: step = 0
        # yy += math.pi/180
        # ambient = (0.0, 0.0, 1.0, 1)
        # glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient)

        xxx = xx
        yyy = yy

        # if step>=1 and step<=45:
        #     # xx = 6/180
        #     xx = 3 * math.cos(step * math.pi / 180) - 3
        # else:
        #     if step >= 46 and step <= 225:
        #         xx = 3 * math.cos(step * math.pi / 180) - 3
        #     else:
        #         if step >= 226 and step <= 360:
        #             xx = 3 * math.cos(step * math.pi / 180) - 3
        #
        # if step>=1 and step<=135:
        #     # yy = 6/180
        #     yy = 3 * math.sin(step * math.pi / 180)
        # else:
        #     if step >= 136 and step <= 315:
        #         yy = 3 * math.sin(step * math.pi / 180)
        #     else:
        #         if step >= 316 and step <= 360:
        #             yy = 3 * math.sin(step * math.pi / 180)

        xx = 3 * math.cos(step * math.pi / 180)
        yy = 3 * math.sin(step * math.pi / 180)

        # x1 = xx
        # y1 = yy


        # print("x = " + str(x1) + " y = " + str(y1))
        # print(step)

        # glTranslatef(xx - xxx, yy - yyy, 0.0)
        # glRotatef(1,10,0.1,0)



    lightpos = (xlig, ylig, zlig)

    glutPostRedisplay()         # Вызываем процедуру перерисовки

def read_texture(filename):
    img = Image.open(filename)
    img_data = numpy.array(list(img.getdata()), numpy.int8)
    textID = glGenTextures(1)
    glBindTexture(GL_TEXTURE_2D, textID)  # This is what's missing
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.size[0], img.size[1], 0, GL_RGB, GL_UNSIGNED_BYTE, img_data)
    return textID

# Процедура перерисовки
def draw():
    global xrot
    global yrot
    global laba1
    global laba2
    global lightpos
    global greencolor
    global redcolor
    global drowmode
    global drowmode2
    global xlig
    global ylig
    global zlig
    global bluecolor

    global xx
    global yy

    global step
    global x1
    global y1
    global z1
    global rotat
    global qobj


    glClear(GL_COLOR_BUFFER_BIT)                                # Очищаем экран и заливаем серым цветом
    glPushMatrix()                                              # Сохраняем текущее положение "камеры"
    glRotatef(xrot, 1.0, 0.0, 0.0)                              # Вращаем по оси X на величину xrot
    glRotatef(yrot, 0.0, 1.0, 0.0)                              # Вращаем по оси Y на величину yrot
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos)                 # Источник света вращаем вместе c о
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    color = (0, 0.4, 0.4, 0)
    # glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color)

    # glutSolidSphere(1, 20, 20)
    # glEnable(GL_COLOR_MATERIAL)
    # glColor4f(1,1,0,1)
    # glBegin(GL_QUADS)
    # glVertex3f(5,5,1)
    # glVertex3f(-5,5,1)
    # glVertex3f(-5, -5, 1)
    # glVertex3f(5, -5, 1)
    # glEnd()
    # glDisable(GL_COLOR_MATERIAL)

    gluSphere(qobj, 1, 50, 50)
    # gluDeleteQuadric(qobj)
    # glDisable(GL_TEXTURE_2D) # текстурная сфера

    # print("x = " + str(x1) + " y = " + str(y1))

    glTranslatef(xx, yy, 0.0)

    print(step)

    glRotatef(rotat + 90, 1, 0, 0)
    glRotatef(rotat - 270, 0, 1, 0)

    glutSolidOctahedron()

    # gluDeleteQuadric(qobj)
    # glDisable(GL_TEXTURE_2D) # текстурная сфера

    #
    # if(laba1):
    #     if(drowmode):
    #         xx = 3
    #         yy = 0
    #         color = (1, 0, 0, 0.0) # 1 прозрачный
    #         glutSolidSphere(1, 20,20)
    #         glTranslatef(xx, yy, 0.0)
    #         glutSolidOctahedron()
    #
    #     else:
    #         glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) # прозрачный куб
    #         glEnable(GL_BLEND)
    #         color = (1, 0, 0, 0.5)
    #         glTranslatef(-0.6, 0.0, 0.0)
    #         glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color)
    #         glutSolidCube(0.3)
    #         glDisable(GL_BLEND) # прозрачный куб
############

            # glTranslatef(0.6, 0.0, 0.0) # текстурная сфера
            # tex = read_texture('pp.jpg')
            # qobj = gluNewQuadric()
            # gluQuadricTexture(qobj, GL_TRUE)
            # glEnable(GL_TEXTURE_2D)
            # glBindTexture(GL_TEXTURE_2D, tex)
            #
            # glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE)
            # gluSphere(qobj, 0.3, 50, 50)
            # gluDeleteQuadric(qobj)
            # glDisable(GL_TEXTURE_2D) # текстурная сфера

############
            # mat_diffuse = (0.2, 1.0, 0.8, 1.0) # отражающийся цилиндр
            # mat_specular = (1.0, 1.0, 1.0, 1.0)
            # mat_shininess = 128.0
            # light_position = (1.1, 1.1, 1.0, 1.0)
            #
            # glLightfv(GL_LIGHT1, GL_POSITION, light_position);
            # glLightfv(GL_LIGHT1, GL_SPECULAR, mat_specular);
            #
            # glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
            # glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
            # glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

            # glTranslatef(0.6, 0.0, -0.25)
            # glutSolidCylinder(0.2, 0.5, 20, 20) # отражающийся цилиндр
            # glutSolidSphere(0.4, 20, 20)

    glPopMatrix()
    glutSwapBuffers()


# Здесь начинается выполнение программы
# Использовать двойную буферизацию и цвета в формате RGB (Красный, Зеленый, Синий)
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
# Указываем начальный размер окна (ширина, высота)
glutInitWindowSize(500, 500)
# Указываем начальное положение окна относительно левого верхнего угла экрана
glutInitWindowPosition(100, 100)
# Инициализация OpenGl
glutInit(sys.argv)
# Создаем окно с заголовком
glutCreateWindow(b"cg2")
# Определяем процедуру, отвечающую за перерисовку
glClear(GL_COLOR_BUFFER_BIT)
# Очищаем экран и заливаем серым цветом



glutDisplayFunc(draw)

# Определяем процедуру, отвечающую за обработку клавиш
glutSpecialFunc(specialkeys)
# Вызываем нашу функцию инициализации
init()
# Запускаем основной цикл
glutMainLoop()

