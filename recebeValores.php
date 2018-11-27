<?php
$acao = $_POST["acao"];
$op = $_GET["op"];

if ($op == "Jqgrid"){
  $ret  = exec("/home/seti/exercicio/WEB/toJSON");
  echo $ret;
}

else if($acao == "cadastro"){
  $nome = $_POST["nome"];
  $login = $_POST["login"];
  $senha = $_POST["senha"];
  $ret  = exec("/home/seti/exercicio/WEB/cadastroUsuario '$nome' '$login' '$senha'");
  echo $ret;
}

else if($acao == "login"){
  $loginUsuario = $_POST["loginUsuario"];
  $senhaUsuario = $_POST["senhaUsuario"];
  $ret  = exec("/home/seti/exercicio/WEB/validaLogin '$loginUsuario' '$senhaUsuario'"); 
  echo $ret;
}

?>