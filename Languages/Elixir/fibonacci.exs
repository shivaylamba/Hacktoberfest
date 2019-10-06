defmodule Fibonacci do
  def nth_value(n), do: nth_value(n, 0, 1)
  def nth_value(n, _, _) when n <= 0, do: raise "Number must be greater than 0"
  def nth_value(1, acc, _), do: acc
  def nth_value(n, current, next), do: nth_value(n - 1, next, current + next)
end

# iex(1)> Fibonacci.nth_value(1)
# 0
