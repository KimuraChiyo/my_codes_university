<!DOCTYPE HTML>
<html lang="ru">
<head>
    <meta charset = "UTF-8">
    <title>Арифметическое кодирование</title>
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
        caption {
            font-weight: bold;
        }
        table {
            text-align: center;
            width: 600px;
            border: 2px solid;
            border-collapse:collapse;
            margin-top: 20px;
            margin-bottom: 20px;
        }
        tr, th, td {
            border: 1px solid;
            width: 200px;
        }
    </style>
</head>
<body>
    <h1>Арифметическое кодирование</h1>
    <div class=".box">
    <form action="" method="post" align="center">
        <input type="text" name="string" placeholder="Введите строку:">
    <br>
    <input type="submit" name="submit" value="Кодирование">
    </form>
    </div>
    <div>
        <?=
            $text ??= '';
            if(isset($_POST['submit'])) {
                $text = $_POST['string'];
            }

            $freqs = get_freq($text);
            $freqs = sorting($freqs);
            output_freqs($freqs);


            $intervals_freq = array();
            $a = 0;
            foreach (array_keys($freqs) as $key) {
                $val = $a + $freqs[$key];
                $intervals_freq[$key] = [$a, $val];
                $a = $val;
            }

            output_intervals($intervals_freq);
            $code = 0;
            output_coded($text, $intervals_freq, $code);
            output_decoded(strlen($text), $code, $intervals_freq);

            function get_freq($text, $par = '') {
                // initializing
                $array = array();
                $arr_size = 0;
                
                // get matches count for every char
                $i = 0;
                while ($i < strlen($text)) {
                    if (isset($array[$text[$i]])) {
                        $array[$text[$i]] = $array[$text[$i]] + 1;
                    } else {
                        $array[$text[$i]] = 1;
                        $arr_size += 1;
                    }
                    $i++;
                }

                // get freqs
                foreach (array_keys($array) as $i) {
                    $array[$i] = ($array[$i] / strlen($text));
                }

                // addon for get freq only one of char in all arr
                // for future
                $res = $array;
                if ($par != '') {
                    $res = $array[$par];
                }
                
                // returning
                return $res;
            }

            function sorting($freqs) {
                $array = array();

                while (count($freqs) > 0) {
                    $max_elem = '';
                    $max_val = -INF;

                    foreach (array_keys($freqs) as $key) {
                        if ($freqs[$key] > $max_val) {
                            $max_elem = $key;
                            $max_val = $freqs[$key];
                        }
                    }
                    $array[$max_elem] = $max_val;
                    unset($freqs[$max_elem]);
                }

                return $array;
            }

            function output_freqs($freqs) {
                echo "
                <div style=\"margin-left: 200px;\">
                <table>
                    <caption>Freqs</caption>
                    <thead>
                        <tr>
                            <th>Letter</th>
                            <th>Frequency</th>
                        </tr>
                    </thead>
                    <tbody>";
                foreach (array_keys($freqs) as $letter) {
                    echo "<tr><th>$letter</th><td>$freqs[$letter]</td></tr>";
                }
                echo "</tbody>
                </table>
                </div>";
            }

            function output_intervals($intervals_freq) {
                echo "
                <div style=\"margin-left: 200px;\">
                <table>
                    <caption>Intervals on [0, 1]</caption>
                    <thead>
                        <tr>
                            <th>Letter</th>
                            <th>Start</th>
                            <th>End</th>
                        </tr>
                    </thead>
                    <tbody>";
                foreach (array_keys($intervals_freq) as $key) {
                    [$start, $end] = $intervals_freq[$key];
                    echo "<tr><th>$key</th><td>$start</td><td>$end</td></tr>";
                }
                echo "</tbody>
                </table>
                </div>";
            }
            
            function output_coded($text, $intervals_freq, &$code) {
                echo "
                <div style=\"margin-left: 200px;\">
                <table>
                    <caption>Coding</caption>
                    <thead>
                        <tr>
                            <th>Letter</th>
                            <th>Start coded number</th>
                            <th>End coded number</th>
                        </tr>
                    </thead>
                    <tbody>";
                $i = 0;
                [$a, $b] = [0, 1];
                while ($i < strlen($text)) {
                    $old_a = $a;
                    $old_b = $b;
                    $b = $old_a + ($old_b - $old_a)*($intervals_freq[$text[$i]][1]);
                    $a = $old_a + ($old_b - $old_a)*($intervals_freq[$text[$i]][0]);
                    echo "<tr><th>$text[$i]</th><td>$a</td><td>$b</td></tr>";
                    $i += 1;
                }
                $code = ($a + $b) / 2;
                echo "</tbody>
                </table>
                </div>";
            }

            function output_decoded($text_len, $code, $intervals_freq) {
                echo "
                <div style=\"margin-left: 200px;\">
                <table>
                    <caption>Decoding</caption>
                    <thead>
                        <tr>
                            <th>Code</th>
                            <th>Letter</th>
                        </tr>
                    </thead>
                    <tbody>";
                $i = 0;
                while ($i < $text_len) {
                    $last_letter = '';
                    foreach (array_keys($intervals_freq) as $letter) {
                        if ($intervals_freq[$letter][0] <= $code && $code < $intervals_freq[$letter][1]) {
                            echo "<tr><td>$code</td><th>$letter</th></tr>";
                            $last_letter = $letter;
                        }
                    }
                    $code = ($code - $intervals_freq[$last_letter][0])/($intervals_freq[$last_letter][1] - $intervals_freq[$last_letter][0]);
                    $i++;
                }
                echo "</tbody>
                </table>
                </div>";
            }
        ?>
    </div>
</body>
</html>

