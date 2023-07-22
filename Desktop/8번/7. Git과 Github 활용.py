from flask import Flask, request, jsonify
from PIL import Image
from io import BytesIO
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, mean_absolute_error
import joblib

app = Flask(__name__)

@app.route("/hello")
def hello():
    return "Hello, World!"

@app.route("/echo")
def echo():
    params = request.args
    return jsonify(params)

@app.route("/upload_image", methods=["POST"])
def upload_image():
    image = request.files.get("image")
    
    if image is None:
        return jsonify({"error": "No image received."}), 400
    
    try:
        img = Image.open(BytesIO(image.read()))
        width, height = img.size
        return jsonify({"width": width, "height": height})
    except Exception as e:
        return jsonify({"error": "Failed to process the image.", "details": str(e)}), 500


@app.route("/predict_score", methods=["GET"])
def predict_score():
    # 데이터 준비
    data = pd.DataFrame({'hours': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
                         'score': [60, 63, 64, 67, 68, 71, 72, 75, 76, 78]})
    X = data[['hours']]
    y = data['score']
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # 선형 회귀 모델 생성 및 평가
    model = LinearRegression()
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    mse = mean_squared_error(y_test, y_pred)
    mae = mean_absolute_error(y_test, y_pred)

    # 새로운 입력에 대한 예측 결과 출력
    hours_to_predict = float(request.args.get("hours", 0))
    predicted_score = model.predict([[hours_to_predict]])

    return jsonify({"score": predicted_score[0]})

@app.route("/predict_image", methods=["POST"])
def predict_image():
    image = request.files.get("image")
    
    if image is None:
        return jsonify({"error": "No image received."}), 400
    
    try:
        img = Image.open(BytesIO(image.read()))
        img = img.resize((150, 150), Image.LANCZOS)
        img_array = tf.keras.preprocessing.image.img_to_array(img)
        img_array = tf.expand_dims(img_array, 0)
        predictions = model.predict(img_array)
        if predictions[0][0] < 0.5:
            predict_result = "고양이"
        else:
            predict_result = "개"

        return jsonify({"predict_result": predict_result})
    except Exception as e:
        return jsonify({"error": "Failed to process the image.", "details": str(e)}), 500


if __name__ == "__main__":
    app.run(debug=True)