<?php
$nome = $_POST["nome"];
$login = $_POST["login"];
$senha = $_POST["senha"];
$ret  = exec("/home/seti/exercicio/WEB/ConectaServidor '$nome' '$login' '$senha'");
echo $ret;
?>

