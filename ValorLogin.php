<?php
$loginUsuario = $_POST["loginUsuario"];
$senhaUsuario = $_POST["senhaUsuario"];
$ret  = exec("/home/seti/exercicio/WEB/validaLogin '$loginUsuario' '$senhaUsuario'");
echo $ret;
?>

