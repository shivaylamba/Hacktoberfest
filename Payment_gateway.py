# Install Stripe package with: pip install stripe
import stripe
from flask import Flask, jsonify, request

# Configure the Stripe API key
stripe.api_key = "your_secret_key"  # Replace with your actual Stripe secret key

app = Flask(__name__)

# Route to create a new payment session
@app.route("/create-checkout-session", methods=["POST"])
def create_checkout_session():
    try:
        # Parse the amount and currency from the request
        data = request.get_json()
        amount = data["amount"]
        currency = data["currency"]

        # Create a Stripe checkout session
        checkout_session = stripe.checkout.Session.create(
            payment_method_types=["card"],
            line_items=[
                {
                    "price_data": {
                        "currency": currency,
                        "product_data": {
                            "name": "Sample Product",
                        },
                        "unit_amount": amount,
                    },
                    "quantity": 1,
                },
            ],
            mode="payment",
            success_url="https://your-domain.com/success",  # Replace with your success URL
            cancel_url="https://your-domain.com/cancel",    # Replace with your cancel URL
        )
        return jsonify({"session_id": checkout_session.id})
    
    except Exception as e:
        return jsonify({"error": str(e)}), 500

if __name__ == "__main__":
    app.run(port=5000)
