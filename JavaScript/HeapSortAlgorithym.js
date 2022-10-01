const heapsort = arr => {
  const a = [...arr];
  let l = a.length;

  const heap = (a, i) => {
    const left = 2 * i + 1;
    const right = 2 * i + 2;
    let max = i;
    if (left < l && a[left] > a[max]) max = left;
    if (right < l && a[right] > a[max]) max = right;
    if (max !== i) {
      [a[max], a[i]] = [a[i], a[max]];
      heap(a, max);
    }
  };

  for (let i = Math.floor(l / 2); i >= 0; i -= 1) heap(a, i);
  for (i = a.length - 1; i > 0; i--) {
    [a[0], a[i]] = [a[i], a[0]];
    l--;
    heap(a, 0);
  }
  return a;
};
