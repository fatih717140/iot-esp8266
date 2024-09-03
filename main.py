#imported flask and render_teplate 
from flask import Flask,render_template
#note:To use a not render template, create a file in the main.py directory.   
#Create a temlates folder and move the index.html file into it

app=Flask(__name__)

@app.route("/")
def İndex():
   return render_template("index.html")

if __name__=="__main__":
    app.run(debug=True)
