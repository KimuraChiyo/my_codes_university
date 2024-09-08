<!DOCTYPE HTML>
<html lang="ru">
<head>
    <meta charset = "UTF-8">
    <title>CSS Grid</title>
    <style>
        .navbar {
            grid-area: navbar;
            background-color: rgb(127,255,212);
            border-radius: 8px;
            text-align: center;
        }
        .main {
            grid-area: main;
            background-color: rgb(127,255,212);
            border-radius: 8px;
            text-align: center;
        }
        .sidebar {
            grid-area: sidebar;
            background-color: rgb(127,255,212);
            border-radius: 8px;
            text-align: center;
        }
        .footer {
            grid-area: footer;
            background-color: rgb(127,255,212);
            border-radius: 8px;
            text-align: center;
        }
        .cont1 {
            grid-area: cont1;
            background-color: rgb(127,255,212);
            border-radius: 8px;
            text-align: center;
        }
        .cont2 {
            grid-area: cont2;
            background-color: rgb(127,255,212);
            border-radius: 8px;
            text-align: center;
        }
        .cont3 {
            grid-area: cont3;
            background-color: rgb(127,255,212);
            border-radius: 8px;
            text-align: center;
        }
        b {
            display: inline-block;
            margin-top: 20px;
        }
        .container {
            display: grid;
            grid-template-columns: 210px 300px 300px 300px;
            grid-template-rows: 150px 432px 300px 150px;
            column-gap: 15px;
            row-gap: 15px;
            grid-template-areas:
                                "navbar navbar navbar navbar"
                                "sidebar main main main"
                                "sidebar cont1 cont2 cont3"
                                "sidebar footer footer footer";
        }
    </style>
</head>
    <body>
        <div class="container">
            <div class="navbar"> <b>Navbar</b> </div>
            <div class="main"> <b>Main</b> </div>
            <div class="sidebar"> <b>Sidebar</b> </div>
            <div class="cont1"> <b>Content-1</b> </div>
            <div class="cont2"> <b>Content-2</b> </div>
            <div class="cont3"> <b>Content-3</b> </div>
            <div class="footer"> <b>Footer</b> </div>
        </div>
    </body>
</html>

