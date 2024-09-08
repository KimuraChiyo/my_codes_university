import pygame
from PIL import Image, ImageDraw
import time

# инициализируем pygame
pygame.init()

# размер окна
WIDTH, HEIGHT = 1600, 800
resolution = (WIDTH, HEIGHT)

# создаём окно
screen = pygame.display.set_mode(resolution)

# ЦВЕТА
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 28)

# генерация фона
# основной цвет поля
field_color = BLACK
image = Image.new("RGB", resolution, field_color)
# рисовать на изображении
drawer = ImageDraw.Draw(image)
# радиус центральной части поля
radius = 40
# ширина линий на поле
line_width = 4
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
paddle_width = 20
# высота
paddle_height = 200
# скорость движения
paddle_speed = 1
# цвет платформы игрока1
color_of_paddle_1 = pygame.Color('green')
# цвет платформы игрока2
color_of_paddle_2 = pygame.Color('yellow')

# стартовые позиции платформ
# стартовая высота
start_height = (HEIGHT - paddle_height) // 2
# промежуток между платформой и границей экрана
space_paddle_screen = 4
# начальная ширина платформы игрока1
start_width_1 = paddle_width - space_paddle_screen
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
ball = pygame.Rect((WIDTH - ball_rect) // 2, (HEIGHT- ball_rect) // 2, ball_rect, ball_rect)

# переменные для движения мяча
dx, dy = 1, -1

# счётчики для правого и левого игрока
left_score, right_score = 0, 0

# победное количество очков
winning_score = 1

# функция для отображения текста
def draw_text(screen, text, x, y, color):
    # имя шрифта
    font_name = pygame.font.match_font('Times New Roman')
    # создание шрифта с именем и размером 50
    font = pygame.font.Font(font_name, 50)
    # рендеринг текста
    text_surface = font.render(text, True, color)
    # расположение и рамки для текста
    text_rect = text_surface.get_rect()
    text_rect.midtop = (x, y)
    # draw text
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

    # ловец событий
    for event in pygame.event.get():
        # закрытие окна и завершение программы через крестик
        if event.type == pygame.QUIT:
            pygame.display.quit()
            exit()

    # размещение задний фон
    screen.blit(background_image, background_position)

    # отрисовка платформ
    pygame.draw.rect(screen, color_of_paddle_1, paddle1)
    pygame.draw.rect(screen, color_of_paddle_2, paddle2)

    # отрисовка мяча
    pygame.draw.circle(screen, color_of_ball, ball.center, ball_radius)

    # отрисовка счёта
    draw_text(screen, str(left_score), WIDTH // 4, HEIGHT // 4, WHITE)
    draw_text(screen, str(right_score), WIDTH // 4 * 3, HEIGHT // 4, WHITE)

    # победное очко
    if left_score == winning_score:
        # если левый выиграл
        # отрисовка текста
        draw_text(screen, 'PLAYER1 WINS!!!!', WIDTH // 2, HEIGHT // 2 - 35, (255, 0, 28))
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
        draw_text(screen, 'PLAYER2 WINS!!!!', WIDTH // 2, HEIGHT // 2 - 35, (255, 0, 28))
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

    # движение мяча
    ball.x += ball_speed * dx
    ball.y += ball_speed * dy

    # коллизия с мячом
    # коллизия с левой стороной экрана
    if ball.centerx - ball_radius < 0:
        # звук победы в раунде
        winning_round_sound.play()
        # отрисовка платформ и мяча в начальное положение
        ball = pygame.Rect((WIDTH - ball_rect) // 2, (HEIGHT - ball_rect) // 2, ball_rect, ball_rect)
        paddle1 = pygame.Rect(start_width_1, start_height, paddle_width, paddle_height)
        paddle2 = pygame.Rect(start_width_2, start_height, paddle_width, paddle_height)
        # добавляем очко правому
        right_score += 1
        # небольшая пауза
        time.sleep(1)
    # коллизия с правой стороной экрана
    elif ball.centerx > WIDTH - ball_radius:
        # звук победы в раунде
        winning_round_sound.play()
        # отрисовка платформ и мяча в начальное положение
        ball = pygame.Rect((WIDTH - ball_rect) // 2, (HEIGHT - ball_rect) // 2, ball_rect, ball_rect)
        paddle1 = pygame.Rect(start_width_1, start_height, paddle_width, paddle_height)
        paddle2 = pygame.Rect(start_width_2, start_height, paddle_width, paddle_height)
        # добавляем очко левому
        left_score += 1
        # небольшая пауза
        time.sleep(1)
    # коллизия мяча с верхней и нижней границей экрана
    if ball.centery < ball_radius or ball.centery + ball_radius > HEIGHT:
        collision_sound.play()
        dy = -dy
    # коллизия мяча с платформами
    if ball.colliderect(paddle1) or ball.colliderect(paddle2):
        collision_sound.play()
        dx = -dx

    # считывание текущих нажатых клавиш на клавиатуре
    keys = pygame.key.get_pressed()
    print(keys)

    # контроль платформ
    # контроль левой платформы(игрок1)
    if keys[pygame.K_w] and paddle1.top > 0:
        paddle1.top -= paddle_speed
    elif keys[pygame.K_s] and paddle1.bottom < HEIGHT:
        paddle1.bottom += paddle_speed

    # контроль левой платформы(игрок2)
    if keys[pygame.K_UP] and paddle2.top > 0:
        paddle2.top -= paddle_speed
    elif keys[pygame.K_DOWN] and paddle2.bottom < HEIGHT:
        paddle2.bottom += paddle_speed

    # выход из игры с помощью Esc
    if keys[pygame.K_ESCAPE]:
        pygame.display.quit()
        exit()

    # обновление заново отрисованных элементов
    pygame.display.flip()