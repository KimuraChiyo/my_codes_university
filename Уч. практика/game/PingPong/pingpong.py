# подключаем графическую библиотеку pygame
import pygame
# подключаем модули для создания изображения поля и рисования на нём
from PIL import Image, ImageDraw
# подключаем библиотеку time для реализации задержек
import time

# инициализируем pygame
pygame.init()

# размер окна
WIDTH, HEIGHT = 800, 400
# разрешение экрана
resolution = (WIDTH, HEIGHT)

# создаём окно и присваиваем ему значение разрешения
screen = pygame.display.set_mode(resolution)

# ЦВЕТА
# RGB белого цвета
WHITE = (255, 255, 255)
# RGB черного цвета
BLACK = (0, 0, 0)
# RGB красного цвета
RED = (255, 0, 28)
# RGB синего цвета
BLUE = (0, 0, 120)

# генерация фона
# основной цвет поля
field_color = BLUE
# с помощью модуля Image из библиотеки pillow создаем изображения формата RGB
# c необходимым разрешением и цветом
image = Image.new("RGB", resolution, field_color)
# штука, чтобы рисовать на изображении
drawer = ImageDraw.Draw(image)
# радиус центральной части поля
radius = 20
# ширина линий на поле
line_width = 2
# цвет линий на поле
field_lines_color = WHITE
# линия от верхней границы окна до верхней границы центральной части поля
drawer.line((WIDTH // 2, 0, WIDTH // 2, HEIGHT // 2 - radius), fill=field_lines_color, width=line_width)
# линия от нижней границы центральной части поля до нижней границы окна
drawer.line((WIDTH // 2, HEIGHT // 2 + radius, WIDTH // 2, HEIGHT), fill=field_lines_color, width=line_width)
# окружность для центральной части поля
drawer.ellipse(((WIDTH // 2 - radius, HEIGHT // 2 - radius), (WIDTH // 2 + radius, HEIGHT // 2 + radius)),
               fill=None,
               outline=field_lines_color,
               width=line_width)
# сохранение изображения для загрузки в pygame
image.save('field.png')

# настройки заднего фона
# задний фон
background_image = pygame.image.load('field.png')
# позиция фона
background_position = (0, 0)

# настройки платформ
# ширина
paddle_width = 10
# высота
paddle_height = 100
# скорость движения
paddle_speed = 1
# цвет платформы игрока1
color_of_paddle_1 = pygame.Color((0, 250, 0))
# цвет платформы игрока2
color_of_paddle_2 = pygame.Color((250, 0, 0))

# стартовые позиции платформ
# стартовая высота
start_height = (HEIGHT - paddle_height) // 2
# промежуток между платформой и границей экрана
space_paddle_screen = 2
# начальная ширина платформы игрока1
start_width_1 = space_paddle_screen
# начальная ширина платформы игрока2(зеркально платформе1)
start_width_2 = WIDTH - paddle_width - start_width_1

# создание платформ
# игрок1
paddle1 = pygame.Rect(start_width_1, start_height, paddle_width, paddle_height)
# игрок2
paddle2 = pygame.Rect(start_width_2, start_height, paddle_width, paddle_height)

# настройки мяча
# цвет
color_of_ball = pygame.Color('white')
# радиус мяча(половина от радиуса центральной части поля)
ball_radius = radius // 2
# cкорость движения
ball_speed = 1
# сторона квадрата, вписанного в окружность мяча
ball_rect = int(ball_radius * 2 ** 0.5)

# создание мяча
ball = pygame.Rect((WIDTH - ball_rect) // 2, (HEIGHT - ball_rect) // 2, ball_rect, ball_rect)

# переменные для движения мяча
dx, dy = 1, -1

# счётчики для правого и левого игрока
left_score, right_score = 0, 0

# победное количество очков
winning_score = 3

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

# ЗВУК
# звук столкновений
collision_sound = pygame.mixer.Sound('pew.wav')
# звук победителя раунда
winning_round_sound = pygame.mixer.Sound('win_round.mp3')
# победил игрок1
player1wins_sound = pygame.mixer.Sound('player1wins.mp3')
# победил игрок2
player2wins_sound = pygame.mixer.Sound('player2wins.mp3')
# празднование победы
winning_sound = pygame.mixer.Sound('WINNING.mp3')

# основной цикл
while True:
    # первая секция платформы1
    paddle1_firstpart = pygame.Rect( start_width_1 + paddle_width, paddle1.top, ball_radius,                         paddle_height // 5)
    # вторая секция платформы1
    paddle1_secondpart = pygame.Rect(start_width_1 + paddle_width, paddle1.top + paddle_height // 5, ball_radius,       paddle_height // 5)
    # третья секция платформы1
    paddle1_thirdpart = pygame.Rect( start_width_1 + paddle_width, paddle1.top + 2 * (paddle_height // 5), ball_radius, paddle_height // 5)
    # четвертая секция платформы1
    paddle1_fourthpart = pygame.Rect(start_width_1 + paddle_width, paddle1.top + 3 * (paddle_height // 5), ball_radius, paddle_height // 5)
    # пятая секция платформы1
    paddle1_fifthpart = pygame.Rect( start_width_1 + paddle_width, paddle1.top + 4 * (paddle_height // 5), ball_radius, paddle_height // 5)

    # первая секция платформы2
    paddle2_firstpart = pygame.Rect( start_width_2 - paddle_width, paddle2.top,                             ball_radius, paddle_height // 5)
    # вторая секция платформы2
    paddle2_secondpart = pygame.Rect(start_width_2 - paddle_width, paddle2.top + paddle_height // 5,        ball_radius, paddle_height // 5)
    # третья секция платформы2
    paddle2_thirdpart = pygame.Rect( start_width_2 - paddle_width, paddle2.top + 2 * (paddle_height // 5),  ball_radius, paddle_height // 5)
    # четвертая секция платформы2
    paddle2_fourthpart = pygame.Rect(start_width_2 - paddle_width, paddle2.top + 3 * (paddle_height // 5),  ball_radius, paddle_height // 5)
    # пятая секция платформы2
    paddle2_fifthpart = pygame.Rect( start_width_2 - paddle_width, paddle2.top + 4 * (paddle_height // 5),  ball_radius, paddle_height // 5)

    # ловец событий
    for event in pygame.event.get():
        # если тип события сравним с нажатием на "Крестик"
        if event.type == pygame.QUIT:
            # закрытие окна
            pygame.display.quit()
            # завершение программы
            exit()

    # размещение задний фон
    screen.blit(background_image, background_position)

    # отрисовка платформы1
    pygame.draw.rect(screen, color_of_paddle_1, paddle1)
    # отрисовка платформы2
    pygame.draw.rect(screen, color_of_paddle_2, paddle2)

    # отрисовка мяча
    pygame.draw.circle(screen, color_of_ball, ball.center, ball_radius)

    # отрисовка счёта левого игрока
    draw_text(screen, str(left_score), WIDTH // 4, HEIGHT // 4, WHITE)
    # отрисовка счёта правого игрока
    draw_text(screen, str(right_score), WIDTH // 4 * 3, HEIGHT // 4, WHITE)

    # победный случай
    if left_score == winning_score:
        # если левый выиграл
        # отрисовка текста
        draw_text(screen, 'PLAYER1 WINS!!!', WIDTH // 2, HEIGHT - 90, (255, 0, 28))
        # обновление экрана
        pygame.display.flip()
        # звук победы левого
        player1wins_sound.play()
        # пауза, чтобы звук полностью проигрался
        time.sleep(2)
        # звук празднования победы
        winning_sound.play()
        # пауза, чтобы звук полностью проигрался
        time.sleep(4)
        # закрытие окна
        pygame.display.quit()
        # остановка программы
        exit()
    elif right_score == winning_score:
        # если правый выиграл
        # отрисовка текста
        draw_text(screen, 'PLAYER2 WINS!!!', WIDTH // 2, HEIGHT - 90, (255, 0, 28))
        # обновление экрана
        pygame.display.flip()
        # звук победы правого
        player2wins_sound.play()
        # пауза, чтобы звук полностью проигрался
        time.sleep(2)
        # звук празднования победы
        winning_sound.play()
        # пауза, чтобы звук полностью проигрался
        time.sleep(4)
        # закрытие окна
        pygame.display.quit()
        # остановка программы
        exit()

    # движение мяча по x
    ball.x += ball_speed * dx
    # движение мяча по y
    ball.y += ball_speed * dy

    # коллизия с мячом
    # коллизия с левой стороной экрана
    if ball.centerx - ball_radius < 0:
        # звук победы в раунде
        winning_round_sound.play()
        # возврат мяча в начальное положение
        ball = pygame.Rect((WIDTH - ball_rect) // 2, (HEIGHT - ball_rect) // 2, ball_rect, ball_rect)
        # возврат платформы1 в начальное положение
        paddle1 = pygame.Rect(start_width_1, start_height, paddle_width, paddle_height)
        # возврат платформы2 в начальное положение
        paddle2 = pygame.Rect(start_width_2, start_height, paddle_width, paddle_height)
        # добавляем очко правому
        right_score += 1
        # небольшая пауза
        time.sleep(1)
    # коллизия с правой стороной экрана
    elif ball.centerx > WIDTH - ball_radius:
        # звук победы в раунде
        winning_round_sound.play()
        # возврат мяча в начальное положение
        ball = pygame.Rect((WIDTH - ball_rect) // 2, (HEIGHT - ball_rect) // 2, ball_rect, ball_rect)
        # возврат платформы1 в начальное положение
        paddle1 = pygame.Rect(start_width_1, start_height, paddle_width, paddle_height)
        # возврат платформы2 в начальное положение
        paddle2 = pygame.Rect(start_width_2, start_height, paddle_width, paddle_height)
        # добавляем очко левому
        left_score += 1
        # небольшая пауза
        time.sleep(1)
    # коллизия мяча с верхней и нижней границей экрана
    if ball.centery < ball_radius or ball.centery + ball_radius > HEIGHT:
        # звук столкновения
        collision_sound.play()
        # отражение мяча по оси y
        dy = -dy
    # коллизия мяча с платформами
    # если мяч контактирует с первыми секциями
    if paddle1_firstpart.collidepoint(ball.centerx, ball.centery) or paddle2_firstpart.collidepoint(ball.centerx, ball.centery):
        # звук столкновения
        collision_sound.play()
        # изменение вектора направления
        dx, dy = -dx, -2
    # если мяч контактирует со вторыми секциями
    elif paddle1_secondpart.collidepoint(ball.centerx, ball.centery) or paddle2_secondpart.collidepoint(ball.centerx, ball.centery):
        # звук столкновения
        collision_sound.play()
        # изменение вектора направления
        dx, dy = -dx, -1
    # если мяч контактирует с третьими секциями
    elif paddle1_thirdpart.collidepoint(ball.centerx, ball.centery) or paddle2_thirdpart.collidepoint(ball.centerx, ball.centery):
        # звук столкновения
        collision_sound.play()
        # изменение вектора направления
        dx, dy = -dx, 0
    # если мяч контактирует с четвертыми секциями
    elif paddle1_fourthpart.collidepoint(ball.centerx, ball.centery) or paddle2_fourthpart.collidepoint(ball.centerx, ball.centery):
        # звук столкновения
        collision_sound.play()
        # изменение вектора направления
        dx, dy = -dx, 1
    # если мяч контактирует с пятыми секциями
    elif paddle1_fifthpart.collidepoint(ball.centerx, ball.centery) or paddle2_fifthpart.collidepoint(ball.centerx, ball.centery):
        # звук столкновения
        collision_sound.play()
        # изменение вектора направления
        dx, dy = -dx, 2

    # считывание текущих нажатых клавиш на клавиатуре
    keys = pygame.key.get_pressed()

    # контроль платформ
    # контроль левой платформы(игрок1)
    # проверка условия для движения вверх
    if keys[pygame.K_w] and paddle1.top > 0:
        # движение вверх
        paddle1.top -= paddle_speed
    # проверка условия для движения вниз
    elif keys[pygame.K_s] and paddle1.bottom < HEIGHT:
        # движение вниз
        paddle1.bottom += paddle_speed

    # контроль правой платформы(игрок2)
    # проверка условия для движения вверх
    if keys[pygame.K_UP] and paddle2.top > 0:
        # движение вверх
        paddle2.top -= paddle_speed
    # проверка условия для движения вниз
    elif keys[pygame.K_DOWN] and paddle2.bottom < HEIGHT:
        # движение вниз
        paddle2.bottom += paddle_speed

    # выход из игры с помощью Esc
    if keys[pygame.K_ESCAPE]:
        # закрытие окна
        pygame.display.quit()
        # завершение программы
        exit()

    # обновление заново отрисованных элементов
    pygame.display.flip()