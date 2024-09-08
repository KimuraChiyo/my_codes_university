<!DOCTYPE HTML>
<html lang="ru">
<head>
    <meta charset = "UTF-8">
    <title>Длина</title>
    <style>
        input {
            margin: 8px;
        }
        form {
            border: 1px solid black;
            width: 500px;
            margin-left: 250px;
        }
        .box {
            width: 1500px;
            height: 500px;
        }
    </style>
</head>
<body>
    <h1>Время звучания звукового файла в формате .wav</h1>
    <div class=".box">
    <form action="" method="post" align="center">
        <input type="text" name="number1" placeholder="Объем файла">
        <br>
        <input type="text" name="number2" placeholder="Частота дискретизации">
        <br>
        <input type="text" name="number3" placeholder="Глубина оцифровки">
    <br>
    <input type="submit" name="submit" value="Посчитать">
    </form>
    </div>
    <div>
        <?=
            $volume ??= '';
            $frequency ??= '';
            $depth ??= '';
            if(isset($_POST['submit'])) {
                $volume = $_POST['number1'];
                $frequency = $_POST['number2'];
                $depth = $_POST['number3'];
            }
            if(is_numeric($volume) && is_numeric($frequency) && is_numeric($depth)) {
                $result = $volume * 8192 / ($frequency * $depth);
                // vol = freq * dep * len / 8192
                // len = vol * 8192 / (freq * dep)
            }
            if (isset($result)) {
                echo "<span style=\"font-size: 28px; color: black; margin-top: 50px; margin-left: 250px\">
                    Время звучания звукового файла равно $result с.
                </span>";
            }
        ?>
    </div>
</body>
</html>

