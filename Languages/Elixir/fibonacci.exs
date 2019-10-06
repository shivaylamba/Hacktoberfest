defmodule Fibonacci do
  def nth_value(n), do: nth_value(n, 0, 1)
  def nth_value(n, _, _) when n <= 0, do: raise "Number must be greater than 0"
  def nth_value(1, acc, _), do: acc
  def nth_value(n, current, next), do: nth_value(n - 1, next, current + next)

  def n_elements(n), do: n_elements(n, [0], 1)
  def n_elements(n, _, _) when n <= 0, do: raise "Number must be greater than 0"
  def n_elements(1, acc, _), do: Enum.reverse(acc)
  def n_elements(n, [h | _] = acc, next), do: n_elements(n - 1, [next | acc], h + next)
end

# iex(1)> Fibonacci.nth_value(1)
# 0
#
# iex(1)> Fibonacci.n_elements(20)
# [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181]
