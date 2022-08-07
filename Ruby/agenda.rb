#Adicionar, Editar e Remover contato;
#Contatos terão as seguintes informações: Nome e telefone;
#Poderemos ver todos os contatos registrados ou somente um contato;

@agenda = [
    {nome:"Lucas", telefone:"999444"},
]

def todos_contatos
    @agenda.each do |contato|
        puts "#{contato[:nome]} - #{contato[:telefone]}"
    end
	puts "-----------------------------------------"
end

def adicionar_contato
    print "Nome: "
    nome = gets.chomp
    print "Telefone: "
    telefone = gets.chomp

    @agenda << {nome: nome, telefone: telefone}
end

def ver_contato
    print "Nome: "
    nome = gets.chomp

    @agenda.each do |contato|
        if contato[:nome].downcase.include?(nome.downcase)
            puts "#{contato[:nome]} - #{contato[:telefone]}"
        end
    end
    puts "-----------------------------------------"
end

def editar_contato
    print "Nome do contato que deseja editar: "
    nome = gets.chomp

    @agenda.each do |contato|
        if contato[:nome].downcase == (nome.downcase)
            print "Novo nome(Enter para cancelar): "
            nome_salvo = contato[:nome]

            contato[:nome] = gets.chomp
            contato[:nome] = contato[:nome].empty? ? nome_salvo : contato[:nome]

            print "Novo teltefone(Enter para cancelar): "
            telefone_salvo = contato[:telefone]

            contato[:telefone] = gets.chomp
            contato[:telefone] = contato[:telefone].empty? ? telefone_salvo : contato[:telefone]
        end
    end
end

def remover_contato
    print "Qual contato deseja remover: "
    nome = gets.chomp

    @agenda.each do |contato|
        if contato[:nome].downcase == (nome.downcase)
            indice = @agenda.index(contato)
            @agenda.delete_at(indice)
            break
        end
    end
end

loop do
    
puts "1- Contatos\n2- Adicionar contatos\n3- Ver contato\n4- Editar contato\n5- Remover contato\n0- Sair"
    codigo = gets.chomp.to_i

    case
    when codigo == 0
        puts "Até mais!"
        break
    when codigo == 1
        todos_contatos
    when codigo == 2
        adicionar_contato
    when codigo == 3
        ver_contato
    when codigo == 4
        editar_contato
    when codigo == 5
        remover_contato
    else
        puts "Função inválida"
    end
end
