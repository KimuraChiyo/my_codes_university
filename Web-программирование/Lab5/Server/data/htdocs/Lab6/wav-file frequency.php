<!DOCTYPE HTML>
<html lang="ru">
<head>
    <meta charset = "UTF-8">
    <title>Частота</title>
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
    <h1>Частота дискретизации звукового файла в формате .wav</h1>
    <div class=".box">
    <form action="" method="post" align="center">
        <input type="text" name="number1" placeholder="Глубина оцифровки">
        <br>
        <input type="text" name="number2" placeholder="Объем файла">
        <br>
        <input type="text" name="number3" placeholder="Длительность звучания">
    <br>
    <input type="submit" name="submit" value="Посчитать">
    </form>
    </div>
    <div>
        <?=
            $depth ??= '';
            $volume ??= '';
            $length ??= '';
            if(isset($_POST['submit'])) {
                $depth = $_POST['number1'];
                $volume = $_POST['number2'];
                $length = $_POST['number3'];
            }
            if(is_numeric($depth) && is_numeric($volume) && is_numeric($length)) {
                $result = $volume * 8192 / ($length * $depth);
                // vol = freq * dep * len / 8192
                // freq = vol * 8192 / (len / dep)
            }
            if (isset($result)) {
                echo "<span style=\"font-size: 28px; color: black; margin-top: 50px; margin-left: 250px\">
                    Частота дискретизации равна $result Гц.
                </span>";
            }
        ?>
    </div>
</body>
</html>

