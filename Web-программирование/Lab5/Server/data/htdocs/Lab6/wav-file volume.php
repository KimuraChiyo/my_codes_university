<!DOCTYPE HTML>
<html lang="ru">
<head>
    <meta charset = "UTF-8">
    <title>Объем</title>
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
    <h1>Объем в Кб звукового файла в формате .wav</h1>
    <div class=".box">
    <form action="" method="post" align="center">
        <input type="text" name="number1" placeholder="Длительность звучания">
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
            $length ??= '';
            $frequency ??= '';
            $depth ??= '';
            if(isset($_POST['submit'])) {
                $length = $_POST['number1'];
                $frequency = $_POST['number2'];
                $depth = $_POST['number3'];
            }
            if(is_numeric($length) && is_numeric($frequency) && is_numeric($depth)) {
                $result = $frequency * $depth * $length / 8192;
                // vol = freq * dep * len / 8192
            }
            if (isset($result)) {
                echo "<span style=\"font-size: 28px; color: black; margin-top: 50px; margin-left: 250px\">
                    Объём файла равен $result Кб.
                </span>";
            }
        ?>
    </div>
</body>
</html>

