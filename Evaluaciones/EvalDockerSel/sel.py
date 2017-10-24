#Hector Mauricio Gonzale Coello
#A01328258

from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from itertools import *
from selenium.webdriver.support.ui import Select

driver = webdriver.Firefox()

def add(driver, nme, tg1, tg2, tg3, tg4, mdl):
    add = driver.find_element(By.XPATH, '//*[@id="content"]/div[1]/div/div/a[1]');
    add.click();

    name = driver.find_element(By.XPATH, '//*[@id="input-name1"]');
    name.send_keys(nme);

    tag1 = driver.find_element(By.XPATH, '//*[@id="input-meta-title1"]');
    tag1.send_keys(tg1);

    tag2 = driver.find_element(By.XPATH, '//*[@id="input-meta-description1"]');
    tag2.send_keys(tg2);

    tag3 = driver.find_element(By.XPATH, '//*[@id="input-meta-keyword1"]');
    tag3.send_keys(tg3);

    tag4 = driver.find_element(By.XPATH, '//*[@id="input-tag1"]');
    tag4.send_keys(tg4);

    data = driver.find_element(By.XPATH, '//*[@id="form-product"]/ul/li[2]/a');
    data.click();

    model = driver.find_element(By.XPATH, '//*[@id="input-model"]');
    model.send_keys(mdl);
    #model.send_keys("MQ8P2LZ/A");

    save = driver.find_element(By.XPATH, '//*[@id="content"]/div[1]/div/div/button');
    save.click();
def select(search):
    driver.get("http://localhost:80");
    srch = driver.find_element(By.XPATH, '//*[@id="search"]/input');
    srch.send_keys(search);
    btn = driver.find_element(By.XPATH, '//*[@id="search"]/div/button');
    btn.click();
    purchase = driver.find_element(By.XPATH, '//*[@id="content"]/div[3]/div/div/div[2]/div[2]/button[1]');
    purchase.click();
def main():
    driver.get("http://localhost/admin/")
    username = driver.find_element(By.ID, "input-username")
    username.send_keys("admin")

    password = driver.find_element(By.ID, "input-password")
    password.send_keys("12345")

    login = driver.find_element(By.CLASS_NAME, "btn-primary")
    login.click();

    catalog = driver.find_element(By.ID, "menu-catalog")
    catalog.click();

    products = driver.find_element(By.XPATH, '//*[@id="collapse1"]/li[2]/a');
    products.click();

    product = driver.find_element(By.XPATH, '//*[@id="collapse1-1"]/li[1]/a');
    product.click();
    add(driver, "iPhone X 256GB", "iPhone", "iPhone", "iPhone", "iPhone", "MQ8P2LZ/A");
    add(driver, "iPhone 8 256GB", "iPhone", "iPhone", "iPhone", "iPhone", "MJ1S2LZ/A");
    select("iPhone X 256GB");
    select("iPhone 8 256GB");

main();