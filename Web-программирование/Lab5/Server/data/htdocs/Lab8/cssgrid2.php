<!DOCTYPE HTML>
<html lang="ru">
<head>
    <meta charset = "UTF-8">
    <title>CSS Grid</title>
    <style>
        .calc-button {
            background-color: rgb(240, 240, 240);
            border-radius: 8px;
            text-align: center;
            /* border: none; */
            font-weight: bold;
            align-self: stretch;
            margin-top: 5px;
        }
        .container {
            display: grid;
            grid-template-columns: repeat(4, 100px);
            grid-template-rows: repeat(5, 40px);
            column-gap: 5px;
            background-color: rgb(245, 245, 245);
            justify-content: center;
            width: 425px;
            height: 205px;
        }
    </style>
</head>
    <body>
        <div class="container">
            <button class="calc-button">C</button>
            <button class="calc-button"><-</button>
            <button class="calc-button">%</button>
            <button class="calc-button">/</button>
            <button class="calc-button">7</button>
            <button class="calc-button">8</button>
            <button class="calc-button">9</button>
            <button class="calc-button">*</button>
            <button class="calc-button">4</button>
            <button class="calc-button">5</button>
            <button class="calc-button">6</button>
            <button class="calc-button">-</button>
            <button class="calc-button">1</button>
            <button class="calc-button">2</button>
            <button class="calc-button">3</button>
            <button class="calc-button">+</button>
            <button class="calc-button">+/-</button>
            <button class="calc-button">0</button>
            <button class="calc-button">,</button>
            <button class="calc-button">=</button>
        </div>
    </body>
</html>

