function cad() {
$.ajax({
url: 'RecebendoValor.php',
type: 'POST',
data: ({
nome: $("#idUsuario").val(),
login: $("#idLogin").val(),
senha: $("#idSenha").val()
}),
success: function (data) {
console.log(data);
//console.log(data);
}
});
}