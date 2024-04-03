import socket
import sqlite3
import random
import pandas as pd
import json
import os


# globais
DB_FILE = "sample_database.db"

# definicoes de funcoes


def db_setup(filename: str):
    DB_FILE = filename


def db_start(dbName: str, dbType: str):
    # Conecta-se ao banco de dados (ele será criado se não existir)
    conn = sqlite3.connect(DB_FILE)
    cursor = conn.cursor()

    # Cria uma tabela de exemplo (você pode modificar isso conforme sua necessidade)
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY,
            username TEXT NOT NULL,
            email TEXT NOT NULL
        )
    """)

    # Commit para salvar as alterações e fecha a conexão
    conn.commit()
    conn.close()


def fetchAll_toJson(rows: list[tuple]) -> str:
    """
    Converte uma lista de tuplas em uma string JSON.

    Args:
        rows (list[tuple]): Lista de tuplas contendo os dados.

    Returns:
        str: String JSON contendo os dados.
    """
    # Lista para armazenar os dados convertidos para JSON
    data = []

    # Converte cada tupla em um dicionário e adiciona à lista
    for row in rows:
        # Cria um dicionário com chaves numeradas sequencialmente
        row_dict = {f"field_{index + 1}": value for index,
                    value in enumerate(row)}
        data.append(row_dict)

    # Converte a lista de dicionários para uma string JSON
    json_string = json.dumps(data, indent=4)

    return json_string


def users_get(sortField: str, sort: Literal["ascending", "descending"], filter: str):
    # Conecta-se ao banco de dados
    conn = sqlite3.connect(DB_FILE)
    cursor = conn.cursor()

    # Executa uma consulta para selecionar todos os registros da tabela users
    cursor.execute("SELECT * FROM users")

    # Recupera todos os resultados da consulta
    rows = cursor.fetchall()

    # Fecha a conexão com o banco de dados
    conn.close()

    return fetchAll_toJson(rows= rows)


def users_populate(num_users):
    # Lista de nomes de usuário e e-mails fictícios
    usernames = ["alice", "bob", "charlie", "dave", "eve"]
    domains = ["example.com", "test.com", "dummy.net"]

    # Conecta-se ao banco de dados
    conn = sqlite3.connect(DB_FILE)
    cursor = conn.cursor()

    # Insere dados fictícios na tabela users
    for _ in range(num_users):
        username = random.choice(usernames) + str(random.randint(1, 100))
        email = username + "@" + random.choice(domains)
        cursor.execute(
            "INSERT INTO users (username, email) VALUES (?, ?)", (username, email))

    # Commit para salvar as alterações e fecha a conexão
    conn.commit()
    conn.close()


from typing import Literal

def users_get(sortField: str, sort: Literal["ascending", "descending"]) -> None:
    # Implemente a lógica da função aqui
    pass
