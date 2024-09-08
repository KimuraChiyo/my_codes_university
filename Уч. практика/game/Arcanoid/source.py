# импортируем графическую библиотеку pygame
import pygame
# импортируем библиотеку random для рандомайзера
from random import randrange as rnd
# импортируем библиотеку time для реализации задержки
from time import sleep

# инициализация pygame
pygame.init()

# разрешение окна
WIDTH, HEIGHT = 1200, 800
# кортеж разрешения для удобства
resolution = (WIDTH, HEIGHT)
# количество кадров в секунду
fps = 30

# создание окна
screen = pygame.display.set_mode(resolution)

# изображение заднего фона
background_image = pygame.image.load('background.jpg')
# позиция для размещения заднего фона
background_position = (0, 0)

# ширина платформы
paddle_width = 200
# высота платформы
paddle_height = 20
# скорость движения платформы
paddle_speed = 3
# цвет платформы
color_of_paddle = pygame.Color('purple')
# начальная ширина расположения платформы
start_width = WIDTH // 2 - paddle_width // 2
# промежуток между экраном и платформой
space_paddle_screen = 4
# начальная высота расположения платформы
start_height = HEIGHT - paddle_height - space_paddle_screen
# создание платформы
paddle = pygame.Rect(start_width, start_height, paddle_width, paddle_height)

# радиус мяча
ball_radius = 20
# скорость мяча
ball_speed = 1
# цвет мяча
color_of_ball = pygame.Color('red')
# сторона квадрата, вписанного в окружность мяча
ball_a = int(ball_radius * 2 ** 0.5)
# создание мяча
ball = pygame.Rect(rnd(ball_a, WIDTH - ball_a), HEIGHT // 2, ball_a, ball_a)
# переменные, отвечающие за перемещение мяча
dx, dy = 1, -1

# генерация блоков
block_list = [pygame.Rect(4 + 80 * i, 4 + 40 * j, 75, 35) for i in range(15) for j in range(8)]
# генерация рандомных цветов для блоков
color_list = [(rnd(30, 256), rnd(30, 256), rnd(30, 256)) for i in range(15) for j in range(8)]


# функция для проверки коллизий с блоками
def detect_collision(dx, dy, ball, rect):
    # если при столкновении dx > 0
    if dx > 0:
        # delta x = правая граница мяча - левая граница прямоугольника
        delta_x = ball.right - rect.left
    # иначе
    else:
        # delta x = правая граница прямоугольника - левая граница мяча
        delta_x = rect.right - ball.left
    # если при столкновении dy > 0
    if dy > 0:
        # delta y = нижняя граница мяча - верхняя граница прямоугольника
        delta_y = ball.bottom - rect.top
    # иначе
    else:
        # delta y = нижняя граница прямоугольника - верхняя граница мяча
        delta_y = rect.bottom - ball.top

    # если небольшая разница между дельтами, то мяч ударился об угол
    if abs(delta_x - delta_y) < 6:
        # полное отражение
        dx, dy = -dx, -dy
    # если delta x больше чем delta y, то мяч ударился в верхнюю/нижнюю границу
    elif delta_x > delta_y:
        # отражение по вертикали
        dy = -dy
    # если delta x больше чем delta y, то мяч ударился в вправую/левую границу
    elif delta_y > delta_x:
        # отражение по горизонтали
        dx = -dx
    # возврат нужных значений
    return dx, dy

# функция для отображения текста
def draw_text(screen, text, x, y, color):
    # имя шрифта
    font_name = pygame.font.match_font('Times New Roman')
    # создание шрифта с именем и размером 70
    font = pygame.font.Font(font_name, 70)
    # рендеринг текста
    text_surface = font.render(text, True, color)
    # вычисление рамки текста
    text_rect = text_surface.get_rect()
    # задание расположения для текста
    text_rect.center = (x, y)
    # отрисовка текста
    screen.blit(text_surface, text_rect)

# основной цикл
while True:
    # ловец событий
    for event in pygame.event.get():
        # закрытие окна и остановка программы с помощью "Выход"
        if event.type == pygame.QUIT:
            # закрытие окна
            pygame.display.quit()
            # остановка программы
            exit()

    # размещение заднего фона в окне
    screen.blit(background_image, background_position)
    # отрисовка платформы
    pygame.draw.rect(screen, color_of_paddle, paddle)
    # отрисовка мяча
    pygame.draw.circle(screen, color_of_ball, ball.center, ball_radius)
    # отрисовка блоков
    [pygame.draw.rect(screen, color_list[color], block) for color, block in enumerate(block_list)]

    # движение мяча по x
    ball.x += ball_speed * dx
    # движение мяча по y
    ball.y += ball_speed * dy

    # если ордината центра мяча меньше радиуса мяча, то коллизия с верхней частью поля
    if ball.centery < ball_radius:
        # отражаем движение по вертикали
        dy = -dy

    # если абсцисса мяча меньше радиуса или больше ширины окна - радиус, то коллизия с правой и левой частью экрана
    if ball.centerx < ball_radius or ball.centerx > WIDTH - ball_radius:
        # отражаем движение по горизонтали
        dx = -dx

    # если мяч столкнулся с платформой
    if ball.colliderect(paddle):
        # отражаем движение по вертикали
        dy = -dy

    # проверка коллизий с блоками
    hit_index = ball.collidelist(block_list)
    # если столкновение есть, то hit_index != -1
    if hit_index != -1:
        # удаляем Rect из списка блоков
        hit_rect = block_list.pop(hit_index)
        # удаляем цвет из списка цветов
        hit_color = color_list.pop(hit_index)
        # реализация коллизии
        dx, dy = detect_collision(dx, dy, ball, hit_rect)
        # повышение количества кадров в секунду(увеличит скорость игры)
        fps += 2

    # если блоков не осталось
    if len(block_list) == 0:
        # отрисовываем текст выигрыша
        draw_text(screen, "YOU WIN!", WIDTH // 2, HEIGHT // 2, pygame.Color('white'))
        # обновление экрана
        pygame.display.flip()
        # небольшая задержка
        sleep(2)
        # закрытие окна
        pygame.display.quit()
        # остановка программы
        exit()

    # если ордината центра мяча больше, чем высота окна - радиус, то коллизия с нижней частью поля
    if ball.centery > HEIGHT - ball_radius:
        # отрисовываем текст проигрыша
        draw_text(screen, "YOU LOSE!", WIDTH // 2, HEIGHT // 2, pygame.Color('white'))
        # обновление экрана
        pygame.display.flip()
        # небольшая задержка
        sleep(2)
        # закрытие окна
        pygame.display.quit()
        # остановка программы
        exit()

    # события нажатых клавиш
    keys = pygame.key.get_pressed()
    # если нажата кнопка "влево" или "a" и левая граница платформы больше нуля
    if (keys[pygame.K_LEFT] or keys[pygame.K_a]) and paddle.left > 0:
        # двигаем платформу влево на значение скорости
        paddle.left -= paddle_speed
    # если нажата кнопка "вправо" или "d" и правая граница платформы меньше ширины поля
    elif (keys[pygame.K_RIGHT] or keys[pygame.K_d]) and paddle.right < WIDTH:
        # двигаем платформу вправо на значение скорости
        paddle.right += paddle_speed

    # обновляем экран
    pygame.display.flip()