import numpy as np

from flask import Flask, request, render_template
from tensorflow.keras.models import load_model
import joblib



app = Flask(__name__)
model = load_model("analysistarp.h5")
sc = joblib.load("scal")



app = Flask(__name__)
@app.route('/')
def home():
    return render_template('home.html')

@app.route('/view',methods =["POST","GET"])
def index():
    if request.method == "POST":
        return render_template('index.html')

@app.route('/login',methods = ["POST","GET"])
def predict():
    
    if request.method == "POST":
        
        la = request.form["Gender"]
        te = request.form["Age"]
        cs = request.form["Do you avoid social events because of overwhelming feelings or fear of how people see you ?"]
        ai = request.form["How often do you feel depressed or hopeless ?"]
        yw = request.form["Have you ever been the victim of social media bullying ?"]
        ho = request.form["Which social media platform you use most ?"]
        yc = request.form["Feeling as if you have no hope for the future."]
        nc = request.form["Is your appetite poor or are you overeating ?"]
        ba = request.form["Have you ever been harassed in any way ?(Physical, sexual, or emotional abuse)"]
        tl = request.form["Do you have suicidal thoughts ?"]
        
        rp = request.form["How would you rate your physical state ?"]
        sp = request.form["How many hours do you sleep per day ?"]
        
        data = [[la,te,cs,ai,yw,ho,yc,nc,ba,tl,rp,sp]]
        print(data)
        data = np.array(data).astype(np.float32)
        #print(data)
        
        data = sc.transform(data)
        print(data)
        
        
        y_pred = np.argmax(model.predict(np.array(data)))
        print(y_pred)
        
       
        
    
      
        
        if y_pred == 0:
            return render_template('mild.html')
        
        elif y_pred == 1:
            return render_template('moderate.html')
        
        elif y_pred == 2:
            return render_template('nodep.html')
        
        elif y_pred == 3:
            return render_template('severe.html')
        
        
        
       

        

        
        
if __name__ == '__main__':
    app.run(debug=True)
    #app.run('0.0.0.0', 8000)
