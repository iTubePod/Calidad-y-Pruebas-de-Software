#Hector Mauricio Gonzalez Coello
#A01328258
require 'watir'
browser = Watir::Browser.new :firefox

browser.goto 'http://blazedemo.com' 
opciones = browser.select_list(:name => "fromPort").options
cont = 0
opciones.each do |op|
    if (cont == 5)
        op.select 
    end
    cont += 1
end
opciones = browser.select_list(:name => "toPort").options
cont = 0
opciones.each do |op|
    if (cont == 4)
        op.select 
    end
    cont += 1
end

browser.button(:type => "submit").click

table = browser.table(:class => "table").trs
cont = 0
table.each do |tr|
  if (cont==5)
  	tr.td(:index => 0).button(:type => "submit").click
  end
  cont +=1
end

browser.text_field(:id => "inputName").set("Hector Mauricio Gonzalez Coello")
browser.text_field(:id => "address").set("Av. Carlos Lazo 100")
browser.text_field(:id => "city").set("Mexico City")
browser.text_field(:id => "state").set("Alvaro Obregon")
browser.text_field(:id => "zipCode").set("01630")

opciones = browser.select_list(:name => "cardType").options
cont = 0
opciones.each do |op|
    if (cont == 1)
        op.select 
    end
    cont += 1
end

browser.text_field(:id => "creditCardNumber").set("1234567891234567")
browser.text_field(:id => "creditCardMonth").set("06")
browser.text_field(:id => "creditCardYear").set("2021")
browser.text_field(:id => "nameOnCard").set("Mauricio G. Coello")
browser.checkbox(:id => "rememberMe").set

browser.button(:type => "submit").click
