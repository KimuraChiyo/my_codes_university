from PIL import Image, ImageDraw


def human(back_color, line_color, cell, line_width):
    image = Image.new('RGB', (cell * 16, cell * 21), back_color)
    radius = cell // 5
    drawer = ImageDraw.Draw(image)

    left_eye_x = 7 * cell
    left_eye_y = 3 * cell
    left_eye_start = (left_eye_x - radius, left_eye_y - radius)
    left_eye_end = (left_eye_x + radius, left_eye_y + radius)
    drawer.ellipse((left_eye_start, left_eye_end), line_color)

    right_eye_x = 9 * cell
    right_eye_y = 3 * cell
    right_eye_start = (right_eye_x - radius, right_eye_y - radius)
    right_eye_end = (right_eye_x + radius, right_eye_y + radius)
    drawer.ellipse((right_eye_start, right_eye_end), line_color)

    left_shoulder_x = 7 * cell
    left_shoulder_y = 6 * cell
    left_shoulder_start = (left_shoulder_x - radius, left_shoulder_y - radius)
    left_shoulder_end = (left_shoulder_x + radius, left_shoulder_y + radius)
    drawer.ellipse((left_shoulder_start, left_shoulder_end), line_color)

    right_shoulder_x = 9 * cell
    right_shoulder_y = 6 * cell
    right_shoulder_start = (right_shoulder_x - radius, right_shoulder_y - radius)
    right_shoulder_end = (right_shoulder_x + radius, right_shoulder_y + radius)
    drawer.ellipse((right_shoulder_start, right_shoulder_end), line_color)

    left_elbow_x = 4 * cell
    left_elbow_y = 10 * cell
    left_elbow_start = (left_elbow_x - radius, left_elbow_y - radius)
    left_elbow_end = (left_elbow_x + radius, left_elbow_y + radius)
    drawer.ellipse((left_elbow_start, left_elbow_end), line_color)

    right_elbow_x = 12 * cell
    right_elbow_y = 10 * cell
    right_elbow_start = (right_elbow_x - radius, right_elbow_y - radius)
    right_elbow_end = (right_elbow_x + radius, right_elbow_y + radius)
    drawer.ellipse((right_elbow_start, right_elbow_end), line_color)

    hip_x = 8 * cell
    hip_y = 11 * cell
    hip_start = (hip_x - radius, hip_y - radius)
    hip_end = (hip_x + radius, hip_y + radius)
    drawer.ellipse((hip_start, hip_end), line_color)

    left_knee_x = 6 * cell
    left_knee_y = 15 * cell
    left_knee_start = (left_knee_x - radius, left_knee_y - radius)
    left_knee_end = (left_knee_x + radius, left_knee_y + radius)
    drawer.ellipse((left_knee_start, left_knee_end), line_color)

    right_knee_x = 11 * cell
    right_knee_y = 10 * cell
    right_knee_start = (right_knee_x - radius, right_knee_y - radius)
    right_knee_end = (right_knee_x + radius, right_knee_y + radius)
    drawer.ellipse((right_knee_start, right_knee_end), line_color)

    left_heel_x = 5 * cell
    left_heel_y = 20 * cell
    left_heel_start = (left_heel_x - radius, left_heel_y - radius)
    left_heel_end = (left_heel_x + radius, left_heel_y + radius)
    drawer.ellipse((left_heel_start, left_heel_end), line_color)

    right_heel_x = 13 * cell
    right_heel_y = 15 * cell
    right_heel_start = (right_heel_x - radius, right_heel_y - radius)
    right_heel_end = (right_heel_x + radius, right_heel_y + radius)
    drawer.ellipse((right_heel_start, right_heel_end), line_color)

    shoulders = (right_shoulder_x, right_shoulder_y, left_shoulder_x, left_shoulder_y)
    drawer.line(shoulders, fill=line_color, width=line_width)

    left_biceps = (left_shoulder_x, left_shoulder_y, left_elbow_x, left_elbow_y)
    drawer.line(left_biceps, fill=line_color, width=line_width)

    right_biceps = (right_shoulder_x, right_shoulder_y, right_elbow_x, right_elbow_y)
    drawer.line(right_biceps, fill=line_color, width=line_width)

    torso = (8 * cell, 5 * cell, hip_x, hip_y)
    drawer.line(torso, fill=line_color, width=line_width)

    left_hip = (hip_x, hip_y, left_knee_x, left_knee_y)
    drawer.line(left_hip, fill=line_color, width=line_width)

    right_hip = (hip_x, hip_y, right_knee_x, right_knee_y)
    drawer.line(right_hip, fill=line_color, width=line_width)

    left_calf = (left_knee_x, left_knee_y, left_heel_x, left_heel_y)
    drawer.line(left_calf, fill=line_color, width=line_width)

    right_calf = (right_knee_x, right_knee_y, right_heel_x, right_heel_y)
    drawer.line(right_calf, fill=line_color, width=line_width)

    left_forearm = (left_elbow_x, left_elbow_y, 6 * cell, 13 * cell)
    drawer.line(left_forearm, fill=line_color, width=line_width)

    right_forearm = (right_elbow_x, right_elbow_y, 15 * cell, 7 * cell)
    drawer.line(right_forearm, fill=line_color, width=line_width)

    left_foot = (left_heel_x, left_heel_y, 7 * cell, 20 * cell)
    drawer.line(left_foot, fill=line_color, width=line_width)

    right_foot = (right_heel_x, right_heel_y, 15 * cell, 14 * cell)
    drawer.line(right_foot, fill=line_color, width=line_width)

    drawer.ellipse(((6 * cell, 1 * cell), (10 * cell, 5 * cell)), fill=None, outline=line_color, width=line_width)
    drawer.arc((6 * cell, 0.5 * cell, 10 * cell, 4.5 * cell), start=45, end=135, fill=line_color, width=line_width)

    image.save('human.png')
