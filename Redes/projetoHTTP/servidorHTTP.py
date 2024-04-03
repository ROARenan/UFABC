# implementação de um servidor base para interpratação de métodos HTTP

import socket
import os

# globais
DB_FILE = "sample_database.db"

# definicoes de funcoes


def http_get(page_ref: str):
    try:
        # abrir o arquivo e enviar para o cliente
        fin = open("htdocs" + page_ref)
        # leio o conteúdo do arquivo para uma variável
        content = fin.read()
        # fecho o arquivo
        fin.close()
        # envia a resposta
        response = "HTTP/1.1 200 OK\n\n" + content

    except FileNotFoundError:
        # caso o arquivo solicitado não exista no servidor, gera uma resposta de erro
        response = "HTTP/1.1 404 NOT FOUND\n\n<h1>ERROR 404!<br>File Not Found!</h1>"

    client_connection.sendall(response.encode())

    client_connection.close()

    return True


def http_put(filename: str, body: str):
    try:
        file_path = os.path.abspath(f"htdocs/{filename}")
        print("Caminho de escrita: ", file_path)

        with open(file_path, "w") as file:
            file.write(body)

        response = "HTTP/1.1 200 OK\n\n" + "Gravacao realizada"
    except:
        response = "HTTP/1.1 404 NOT FOUND\n\n<h1>ERROR 404!<br>File Not Found!</h1>"

    client_connection.sendall(response.encode())

    client_connection.close()
    
    return response


# definindo o endereço IP do host
SERVER_HOST = ""
SERVER_PORT = 8080

# vamos criar o socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind((SERVER_HOST, SERVER_PORT))

# coloca o socket para escutar por conexões
server_socket.listen(1)

# mensagem inicial do servidor
print("Servidor em execução...")
print("Escutando por conexões na porta %s" % SERVER_PORT)
print(
    f"URL: http://{socket.gethostbyname(socket.gethostname())}:{SERVER_PORT}")

while True:
    # espera por conexões
    client_connection, client_address = server_socket.accept()

    request = client_connection.recv(1024).decode()
    if request:
        # imprime a solicitação do cliente
        print(request)

        # analisa a solicitação HTTP
        headers = request.split("\n")
        #print(headers)

        # pega o nome do arquivo sendo solicitado
        filename = headers[0].split()[1]
        method = headers[0].split()[0]

        # verifica qual arquivo está sendo solicitado e envia a resposta para o cliente
        if filename == "/":
            filename = "/index.html"

        # verifica o tipo de request
        if method == "GET":
            print("Solicitacao GET recebida")
            http_get(filename)
        elif method == "PUT":
            print("Solicitacao PUT recebida")
            http_put("new_HTML.html", "<html><head><title>Título</title></head><body><h1>Conteúdo</h1></body></html>")

server_socket.close()