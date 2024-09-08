<!DOCTYPE HTML>
<html lang="ru">
<head>
    <meta charset = "UTF-8">
    <title>CSS Grid</title>
    <style>
        .first, .second, .third, .fourth {
            border: 1px dashed;
        }
        .first {
            grid-area: first;
        }
        .second {
            border-left: none;
            grid-area: second;
        }
        .third {
            border-top: none;
            grid-area: third;
        }
        .fourth {
            border-left: none;
            border-top: none;
            grid-area: fourth;
        }
        .container {
            padding-top: 40px;
            padding-bottom: 40px;
            padding-right: 100px;
            padding-left: 100px;
            display: grid;
            grid-template-columns: 340px 340px;
            grid-template-rows: 204px 204px;
            grid-template-areas:
                                "first second"
                                "third fourth";
            background-color: rgb(252,244,209);
            width: 680px;
            height: 408px;
        }
        .b, .c, .d, .e, .h, .i, .j, .l {
            border: 1px dashed;
        }
        .a, .f, .g, .l {
            font-size: 64px;
            font-weight: bold;
        }
        .b, .c, .d, .e, .h, .i, .j, .k {
            font-size: 30px;
            font-weight: bold;
        }
        .a {
            padding-top: 40%;
            padding-left: 45%;
            grid-area: a;
        }
        .b {
            border-left: none;
            border-right: none;
            border-bottom: none;
            padding-top: 15%;
            padding-left: 70%;
            grid-area: b;
        }
        .c {
            border-top: none;
            border-bottom: none;
            padding-top: 130%;
            padding-left: 40%;
            grid-area: c;
        }
        .d {
            border-top: none;
            border-right: none;
            padding-top: 20%;
            padding-left: 70%;
            grid-area: d;
        }
        .e {
            border-top: none;
            padding-top: 40%;
            padding-left: 40%;
            grid-area: e;
        }
        .f {
            padding-top: 40%;
            padding-left: 45%;
            grid-area: f;
        }
        .g {
            padding-top: 40%;
            padding-left: 45%;
            grid-area: g;
        }
        .h {
            border-left: none;
            border-right: none;
            border-bottom: none;
            font-size: 38px; 
            padding-top: 15%; 
            padding-left: 60%;
            grid-area: h;
        }
        .i {
            border-bottom: none;
            padding-top: 130%; 
            padding-left: 40%;
            grid-area: i;
        }
        .j {
            border-top: none;
            border-bottom: none;
            padding-top: 20%;
            padding-left: 70%;
            grid-area: j;
        }
        .k {
            padding-top: 40%;
            padding-left: 40%;
            grid-area: k;
        }
        .l {
            border-left: none;
            border-right: none;
            padding-top: 40%;
            padding-left: 45%;
            grid-area: l;
        }
        .top {
            display: grid;
            grid-template-columns: 68px 68px 68px 68px 68px;
            grid-template-rows: 68px 68px 68px;
            grid-template-areas: "a a d d e"
                                 "a a c f f"
                                 "b b c f f"; 
            background-color: rgb(252,244,209);
            overflow:hidden;
        }
        .bottom {
            display: grid;
            grid-template-columns: repeat(5, 68px);
            grid-template-rows: repeat(3, 68px);
            grid-template-areas: "k j j g g"
                                 "l l i g g"
                                 "l l i h h"; 
            background-color: rgb(252,244,209);
            overflow:hidden;
        } 
    </style>
</head>
    <body>
        <div class="container">
            <div class="first top">
                <div class="a" style="background-color: rgb(204,221,187);">13</div>
                <div class="b" style="background-color: rgb(248,233,160);">22</div>
                <div class="c"> &ensp;5</div>
                <div class="d"> &ensp;9</div>
                <div class="e" style="background-color: rgb(199,216,219);">18</div>
                <div class="f" style="background-color: rgb(247,217,197);"> &ensp;6</div></div>
            <div class="second top">
                <div class="a" style="background-color: rgb(248,233,160);"> &ensp;1</div>
                <div class="b"> &ensp;8</div>
                <div class="c" style="background-color: rgb(199,216,219);">11</div>
                <div class="d">20</div>
                <div class="e" style="background-color: rgb(247,217,197);">15</div>
                <div class="f"> &ensp;3</div></div>
            <div class="third bottom">
                <div class="g" style="font-size: 38px; font-weight: bold; padding-top: 60%; padding-left: 60%;"> &ensp;2</div>
                <div class="h">12</div>
                <div class="i">17</div>
                <div class="j">16</div>
                <div class="k"> &ensp;7</div>
                <div class="l" style="background-color: rgb(199,216,219);">24</div></div>
            <div class="fourth bottom">
                <div class="g" style="background-color: rgb(248,233,160);">21</div>
                <div class="h">10</div>
                <div class="i">23</div>
                <div class="j">14</div>
                <div class="k" style="background-color: rgb(247,217,197);">19</div>
                <div class="l" style="background-color: rgb(204,221,187);"> &ensp;4</div></div>
        </div>
    </body>
</html>

