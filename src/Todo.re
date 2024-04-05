type todo = {
    id: string,
    text: string,
    isDone: bool
};
[@react.component]
let make = (~id, ~text, ~isDone, ~markDone) => {
    <li>
        
        {
            switch (isDone) {
            | true => <span style=(ReactDOM.Style.make(~textDecoration="line-through", ()))> {React.string(text)}</span>
            | false => <span>{React.string(text)}</span>
            }
        }
        <button onClick={_ =>markDone(id)} >{React.string("Toggle")}</button>
    </li>
}